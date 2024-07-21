// Дана целочисленная квадратная матрица 10 х 10. реализовать алгоритм вычисления суммы максимальных элементов из каждой строки.
// Напечатать значение этой суммы. Предполагается, что в каждой строке такой элемент единственный.
// Реализовать функцию поиска максимума в строке из 10 элементов

#include <stdio.h>
#include <limits.h>

const int SIZE = 10;

int main(int argc, char **argv)
{
    int a[SIZE][SIZE];
    int maxs_summ = 0, string_max = INT_MIN;
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j ++) {
            scanf("%d", &a[i][j]);
            string_max = a[i][j] > string_max ? a[i][j] : string_max;
        }
        maxs_summ += string_max;
        string_max = 0;
    }
    printf("%d", maxs_summ);
}