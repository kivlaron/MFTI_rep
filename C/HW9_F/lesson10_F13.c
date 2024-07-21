// Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива.
// Прототип функции int count_between(int from, int to, int size, int a[])
// Например, на отрезке [4, 6] в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения

#include <stdio.h>

int count_between(int from, int to, int size, int a[]);

int main(int argc, char **argv)
{
    //int size = 12, from = 4, to = 6;
    int size = 12, from = 80, to = 89;
    //int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a[] = {77, 81, 2, 88, 57, 64, 49, 33, 28, 58};
    printf("%d", count_between(from, to, size, a));
}

int count_between(int from, int to, int size, int a[]) {
    int count = 0;
    for (int i = 0; i < size; i ++) {
        if ((a[i] >= from) && (a[i] <= to)) {
            count ++;
        }
    }
    return count;
}