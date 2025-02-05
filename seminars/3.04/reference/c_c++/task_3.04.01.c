#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int info;
};

// Функция освобождения памяти
void freeMemory(struct node *lst) {
    struct node *now = lst, *next = lst;
    while (next) {
        next = now->next;
        free(now);
        now = next;
    }
    puts("\nNow memory is free!");
}

// Функция вывода списка на экран
void printList(struct node *lst) {
    if (!lst) {
        puts("List is empty!");
    } else {
        while (lst) {
            printf("%7d", lst->info);
            lst = lst->next;
        }
        printf("\n");
    }
}

// Функция создания упорядоченного списка (по возрастанию)
// Возвращает указатель на первую запись
struct node *queueSorted() {
    int n, prevN;
    struct node *add, *last, *first = NULL;
    // Сначала список пуст

    printf("Enter positive integers:\n");
    if (!scanf("%d", &n) || n <= 0)
        return first;
    else{
        first = (struct node *)malloc(sizeof(struct node));
        // Выделим память для первой записи
        first->info = n;
        last = first;
        prevN = n; // Запомним предыдущее число

        while (scanf("%d", &n) == 1 && n > 0) { // Ввод до Ctrl+Z или n<=0

            if (prevN <= n) {
                add = (struct node *)malloc(sizeof(struct node));
                // Память для добавляемой записи
                add->info = n; last->next = add; // Присоединим её к cписку
                last = add;
                prevN = n;
            } else {
                puts("Error: Enter new number!");
                while (getchar() != '\n');
            }
        }
        // Cделаем эту запись последней
        last->next = NULL;
        return first; // Вернем адрес начала списка
    }
}

// Функция вставки элемента в упорядоченный список
struct node *insertSorted(struct node *first, int n) {
    struct node *curr, *prev, *add;

    add = (struct node *)malloc(sizeof(struct node));
    add->info = n;

    // Вставка в начало списка
    if (!first)
        add->next = NULL; first = add;
    else {
        if (first->info == n) {
            add->next = first;  first = add;
        }
        else {
            curr = first;
            while (curr->next != NULL && curr->info < n) {
                prev = curr;
                curr = curr->next;
            }
            if (curr->info >= n) {
                add->next = curr; prev->next = add;
            }
            else {
                curr->next = add; add->next = NULL;
            }
        }
    }

    return first;
}

int main() {
    puts("*************************************");
    puts("*      Seminar 3.04. Task №01       *");
    puts("*************************************\n");

    struct node *first;
    int n;

    first = queueSorted();
    printList(first);

    printf("Enter number: ");
    while (getchar() != '\n'); // Очистка буфера ввода
    if (scanf("%d", &n)) {
        first = insertSorted(first, n);
        printf("Changed list:\n");
        printList(first);
    }

    freeMemory(first);
    return 0;
}
