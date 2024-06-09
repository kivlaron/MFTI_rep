// Написать только одну логическую функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых.
// Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
// int is_two_same(int size, int a[]);

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_two_same(int size, int a[]);

int main(int argc, char **argv)
{
    int a[100];
    int size = sizeof(a)/sizeof(a[0]);
    srand(time(NULL));
    for (int i = 0; i < size; i ++) {
        a[i] = rand() % 10000;
        printf(" %d", a[i]);
    }
    printf("\n");
    printf("%d", is_two_same(size, a));
    return 0;
}

int is_two_same(int size, int a[]) {
    for (int i = 0; i < size; i ++)
        for (int j = 0; j < size; j ++)
            if (i != j)
                if (a[i] == a[j])
                    return 1;
    return 0;
}