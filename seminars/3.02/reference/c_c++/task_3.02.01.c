#include <malloc.h>
#include <stdio.h>
#include <string.h>

void input(char *text[]) {
  char buf[81];  // буфер для ввода строки
  while (gets(buf) != NULL) {
    // выделение памяти для cтроки и запоминание ее адреса
    *text = (char *)malloc(strlen(buf) + 1);
    // копирование содержимого буфера в динамическую память
    strcpy(*text++, buf);
  }
  *text = NULL;
}

void freeText(char *text[]) { // или void freeText(char **text) {
  while (*text != NULL) free(*text++);
}

int main() {
  puts("*************************************");
  puts("*      Seminar 3.02. Task №01       *");
  puts("*************************************\n");
  char *text[30], **i;
  puts("Input strings:");
  input(text);
  // для окончания ввода данных Ctrl+Z (Windows) или Ctrl+D (Linux) на отдельной строке
  if (!(*text))
    puts("No text!");
  else {
    i = text;
    puts("Your text:");
    while (*i != NULL) {
      puts(*i);
      i++;
    }
    freeText(text);
    puts("Now memory is free!");
  }
}