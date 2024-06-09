// Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел, сколько элементов
// превосходят по модулю максимальный элемент. Прототип функции int count_bigger_abs(int n, int a[]);
// Например, на отрезке [4, 6] в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения

#include <stdio.h>

int count_bigger_abs(int n, int a[]);;

int main(int argc, char **argv)
{
    int size = 10, from = 6, to = 4;
    int a[] = {1, -20, 3, 4, -50, 6, 7, 8, 9, 10};
    printf("%d", count_bigger_abs(size, a));
}

int count_bigger_abs(int n, int a[]) {
    int max = a[0], count = 0;
    for (int i = 0; i < n; i ++) {
        max = a[i] > max ? a[i] : max;
    }
    for (int i = 0; i < n; i ++) {
        if ((a[i] < 0 ? a[i]*(-1) : a[i]) > max)
            count ++;
    }
    return count;
}