// Составить функцию которая находит след матрицы в двумерном массиве. Показать пример ее работы на матрице из 5 на 5 элементов.
// След матрицы - это сумма элементов на главной диагонали.

#include <stdio.h>

const int SIZE = 25;

int main(int argc, char **argv)
{
    int a[SIZE];
    int main_summ = 0;
    for (int i = 0; i < SIZE; i ++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < SIZE/5; i ++) {
        main_summ += a[5*i + i];
    }
    printf("%d", main_summ);
}