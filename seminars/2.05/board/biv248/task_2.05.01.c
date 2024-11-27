#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define strLen 81

// поиск подстрок
void selectSubStrings(
  int nStr, char arrStr[][strLen],
  int *nSubStr, char arrSubStr[][strLen], int arrNum[]) {
  
  int i, j, p = 0;
  *nSubStr = 0;

  for (i = 0; i < nStr; ++i){
    p = 0;
    for (j = 0; j < strlen(arrStr[i]); ++j) {
      if (arrStr[i][j] != ']' && arrStr[i][j] != '['){
        arrSubStr[*nSubStr][p++] = arrStr[i][j];
      }
      else if(p > 0){
        arrNum[*nSubStr] = i;
        arrSubStr[(*nSubStr)++][p] = '\0';
        p = 0; 
      }
    }

    if(p){
      arrNum[*nSubStr] = i;
      arrSubStr[(*nSubStr)++][p] = '\0';
    }
  }
}

// поиск номера подстроки (вернет –1 если нет нужной подстроки)
int searchSubStringNumber(
  int nSubStr, char arrSubStr[][strLen]) {// возвращает номер подстроки
  
  int max_num = 0; 
  int i_max = -1;
  
  char *s;
  for(int i = 0; i < nSubStr; i++){
    s = arrSubStr[i];
    while(*s && isdigit(*s)){
      s++;
    }

    if(s - arrSubStr[i] > max_num){
      max_num = s - arrSubStr[i];
      i_max = i;
    }
    
  }
  return i_max;
}

// преобразование исходной строки
// возвращает признак преобразования
int transformString(char *s) {
  int i = 0, j, kol=0;
  for (i=strlen(s)-1;i>=0&&*(s+i)==' ';i--);
  kol+=strlen(s)-i-1;
  *(s+1+i)='\0';
  for (i=0;i<strlen(s)&&*(s+i)==' ';i++);
  for (j=i;j<strlen(s);j++){
    *(s+j-i)=*(s+j);
  }
  kol+=i;
  return kol;
}

int main() {
  char arrStr[10][strLen], arrSubStr[30][strLen];
  int i, i1, nStr = 0, nSubStr, arrNum[30], f;

  // ввод строк до пустой или CTRL+Z
  puts("Input strings:");
  while (*gets(arrStr[nStr]) && *arrStr[nStr] && nStr < 10)
    nStr++;

  selectSubStrings(nStr, arrStr, &nSubStr, arrSubStr, arrNum);

  puts("Obtained results:");
  if (nSubStr == 0)
    puts("1. No substrings!");
  else {
    puts("1. Substings:");
    for (i = 0; i < nSubStr; i++)
      puts(arrSubStr[i]);
    i1 = searchSubStringNumber(nSubStr, arrSubStr);
    if (i1 == -1)
      puts("2. No necessary substring!");
    else {
      puts("2. Substring with the maximum number of digits in the beginning:");
      puts(arrSubStr[i1]);
      int countSpaces = transformString(arrStr[arrNum[i1]]);
      if (countSpaces) {
        printf("3. %d\'th line of source array has been converted (%d spaces was deleted):\n",
                arrNum[i1], countSpaces);
        // преобразованная %d-я строка исходного массива
        puts(arrStr[arrNum[i1]]);
      }
      else
        puts("3. No transformed string!");
    }
  }
  return 0;
}