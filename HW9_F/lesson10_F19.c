// Определить количество положительных элементов квадратной матрицы, превышающих по величине среднее арифметическое всех элементов главной диагонали.
// Реализовать функцию среднее арифметическое главной диагонали.

#include <stdio.h>
#include <limits.h>

const int SIZE = 5;

float average(int a[SIZE][SIZE]);

int main(int argc, char **argv)
{
    int a[SIZE][SIZE], avr, count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    avr = average(a);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((a[i][j] > 0) && (a[i][j] > avr))
            {
                count ++;
            }
        }
    }
    printf("%d", count);
}

float average(int a[SIZE][SIZE])
{
    int summ = 0;
    for (int i = 0; i < SIZE; i++)
    {
        summ += a[i][i];
    }
    return summ / SIZE;
}