#include <stdio.h>
#include <string.h>
#include <time.h>
#define M 100
#define L 81
#define CLR while (getchar() != '\n');
#define maxPhoneWeight 1500

// Описание структуры данных
struct phone {
  struct {
    int year, month;
  } date;

  char firm[L], color[L];
  int weight;
};

// Ввод целого числа в границах от min до мах,
// s - наименование поля.
int inputIntNumberCheck(int min, int max, char s[]) {
  float a;
  int b;
  do
  {
    printf("Input %s:", s);
    b = scanf("%f", &a);
    while(getchar() != '\n');
  } while((int) a != a || b != 0);
  return (int) a;
}

// Ввод строки, которая обязательно содержит хотя бы 1 символ.
void inputStringCheck(char name[], char s[]) {
  char b[L];
  do
  {
    printf("Input %s:\n", s);
    gets(b);
  } while(!b);
  return b; 
}

// Ввод структур телефонов.
int inputPhones(struct phone phones[]) {
  int k, i;
  // Возвр. число секунд с полуночи 1 янв. 1970.
  time_t t = time(NULL);
  // Структура, содержащая дату и время.
  // Запрашиваем текущее время.
  struct tm *today = localtime(&t);
  // Колчество лет начинается с 1900 г.
  int year = today->tm_year + 1900;
  k = inputIntNumberCheck(1, M, "number of phones");
  for (i = 0; i < k; i++) {
    printf("Phone #%d\n", i + 1);
    phones[i].date.year = inputIntNumberCheck(1881, year, "year");
    phones[i].date.month = inputIntNumberCheck(1, 12, "month");
    inputStringCheck("firm", phones[i].firm);
    phones[i].weight = inputIntNumberCheck(1, maxPhoneWeight, "weight");
    inputStringCheck("color", phones[i].color);
  }
  return k;
}

void outputPhones(struct phone phones[], int phoneCount) {
  for (int i = 0; i < phoneCount; i++) {
    printf("Phone #%d\n", i + 1);
    printf("\tYear: %d\n", phones[i].date.year);
    printf("\tMonth: %d\n", phones[i].date.month);
    printf("\tFirm: %s\n", phones[i].firm);
    printf("\tWeight: %d\n", phones[i].weight);
    printf("\tColor: %s\n", phones[i].color);
    printf("Use any key to continue...\n");
    getchar();
  }
}

// Найти все фирмы, выпускающие самые легкие телефоны.
// firmsCount – количество подходящих телефонов.
int searchLightestPhone(struct phone phones[], int phoneCount,
                        char firms[][L]) {
  int low_weight = -1;
  int num_firms = 0;

  for (size_t i = 0; i < phoneCount; i++)
  {
    if (low_weight == -1 || phones[i].weight <= low_weight)
    {
      if (low_weight == -1 || phones[i].weight < low_weight)
      {
        low_weight = phones[i].weight;
        num_firms = 0;
      }

      strncpy(firms[num_firms], phones[i].firm, L);
      num_firms++;
    }
  }
  return num_firms;
}

// Вывод полученного списка фирм
void outputSearchResult(int firmsCount, char firms[][L]) {
  printf("Different firms that produce the lightest phones:\n");
  for (int i = 0; i < firmsCount; i++) printf("\t%d. %s\n", i + 1, firms[i]);
}

// Массив указателей на телефоны, выпущенных до заданной даты.
int searchPhoneBeforeDate(struct phone phones[], int phoneCount,
                          struct phone *phoneBeforeDate[]) {
  
}

// Вывод телефонов, выпущенных до указанной даты
void outputFoundedPhone(struct phone *phoneBeforeDate[],
                        int phoneBeforeDateCount) {
  
}

int main() {
  puts("*************************************");
  puts("*      Seminar 3.01. Task №01       *");
  puts("*************************************\n");
  struct phone phones[M], *phoneBeforeDate[M];
  int phoneCount, firmsCount, phoneBeforeDateCount;
  char firms[M][L];

  // Ввод данных и контрольный вывод
  phoneCount = inputPhones(phones);
  outputPhones(phones, phoneCount);

  // Поиск фирм, выпускающих самые легкие телефоны
  firmsCount = searchLightestPhone(phones, phoneCount, firms);
  outputSearchResult(firmsCount, firms);

  // Поиск телефонов, выпущенных до указанной даты
  phoneBeforeDateCount =
      searchPhoneBeforeDate(phones, phoneCount, phoneBeforeDate);
  outputFoundedPhone(phoneBeforeDate, phoneBeforeDateCount);
  return 0;
}