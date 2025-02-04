#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int info;
};

// Функция создания стека
struct node *stack() {
    int n;
    struct node *add, *last, *first = NULL;
    
    printf("Enter positive integers:\n");
    while (scanf("%d", &n) == 1 && n > 0) {
        add = (struct node *)malloc(sizeof(struct node));
        add->info = n;
        add->next = first; // добавление в начало (стек)
        first = add;
    }
    return first;
}

// Функция вывода списка
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

// Функция создания нового списка (из элементов, кратных 3)
struct node *newList(struct node *first) {
    struct node *curr, *lastNew, *currNew, *firstNew;
    curr = first;
    firstNew = NULL;

    while (curr != NULL) {
        if (curr->info % 3 == 0) {
            if (firstNew == NULL) {
                firstNew = (struct node *)malloc(sizeof(struct node));
                lastNew = firstNew;
            }

            currNew = lastNew;
            lastNew = (struct node *)malloc(sizeof(struct node));

            currNew->info = curr->info;
            currNew->next = lastNew;
        }
        curr = curr->next;
    }

    if (firstNew != NULL) {
        currNew->next = NULL;
        free(lastNew);
    }

    return firstNew;
}

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

int main() {
    puts("*************************************");
    puts("*      Seminar 3.03. Task №03       *");
    puts("*************************************\n");

    struct node *firstNew, *first;
    first = stack();

    if (!first) {
        puts("Original list is empty");
    } else {
        puts("Original list:");
        printList(first);

        firstNew = newList(first);

        if (!firstNew) {
            puts("New list is empty");
        } else {
            puts("New list:");
            printList(firstNew);
            freeMemory(firstNew);
            puts("New list was deleted");
        }

        freeMemory(first);
        puts("Original list was deleted");
    }

    return 0;
}
