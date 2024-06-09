// Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
// Прототип функции int sum_between_ab(int from, int to, int size, int a[])

#include <stdio.h>

int sum_between_ab(int from, int to, int size, int a[]);

int main(int argc, char **argv)
{
    int size = 10, from = 6, to = 4;
    //int size = 10, from = 80, to = 89;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //int a[] = {77, 81, 2, 88, 57, 64, 49, 33, 28, 58};
    printf("%d", sum_between_ab(from, to, size, a));
}

int sum_between_ab(int from, int to, int size, int a[]) {
    int count = 0;
    for (int i = 0; i < size; i ++) {
        if (((a[i] >= from) && (a[i] <= to)) || ((a[i] <= from) && (a[i] >= to))) {
            count += a[i];
        }
    }
    return count;
}