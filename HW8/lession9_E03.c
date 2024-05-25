// Считать массив из 10 элементов и найти в нем максимальный и
// минимальный элементы и их номера.
#include <stdio.h>

const int SZ = 10;

void inputArr(int arr[]);
int minNum(int arr[]);
int maxNum(int arr[]);

int main(void)
{
    int arr[SZ];
    inputArr(arr);
    printf("%d %d %d %d", maxNum(arr), arr[maxNum(arr) - 1], minNum(arr), arr[minNum(arr) - 1]);
    return 0;
}

void inputArr(int arr[]) {
    for (int i = 0; i < SZ; i ++)
        scanf("%d", &arr[i]);
}

int minNum(int arr[]) {
    int min_index = 0;
    for (int i = 1; i < SZ; i++)
    {
        min_index = arr[min_index] > arr[i] ? i : min_index;
    }
    return min_index + 1;
}

int maxNum(int arr[]) {
    int max_index = 0;
    for (int i = 1; i < SZ; i++)
    {
        max_index = arr[max_index] < arr[i] ? i : max_index;
    }
    return max_index + 1;
}
