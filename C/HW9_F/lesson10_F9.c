// Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива.
// Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. Если отрицательных элементов нет - массив не менять.
// Прототип функции: void swap_negmax_last(int size, int a[])

#include <stdio.h>
#include <stdlib.h>

const int SIZE = 10;

void swap_negmax_last(int size, int a[]);

int main(int argc, char **argv)
{
    //int a[SIZE];
    //srand(1);
    //for (int i = 0; i < SIZE; i++)
    //{
    //    a[i] = ((rand() / 10) * 3) / 100 - 50;
    //    printf("%d, ", a[i]);
    //}
    int a[] = {1, -2, -3, -4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d, ", a[i]);
    }
    swap_negmax_last(SIZE, a);
    printf("\n----------\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d, ", a[i]);
    }
    return 0;
}

void swap_negmax_last(int size, int a[])
{
    int max_neg_index = 0;
    _Bool neg_exist = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            if (!neg_exist) {
                neg_exist = 1;
                max_neg_index = i;
            }
            max_neg_index = (a[i] > a[max_neg_index]) ? i : max_neg_index;
        }
    }
    if (neg_exist)
    {
        int tmp = a[size - 1];
        a[size - 1] = a[max_neg_index];
        a[max_neg_index] = tmp;
    }
}