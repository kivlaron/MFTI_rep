// Считать массив из 12 элементов и посчитать среднее арифметическое
// элементов массива.
#include <stdio.h>

const int SZ = 12;

void inputArr(int arr[]);
float average(int arr[]);

int main(void)
{
    int arr[SZ];
    inputArr(arr);
    printf("%.2f", average(arr));
    return 0;
}

void inputArr(int arr[]) {
    for (int i = 0; i < SZ; i ++)
        scanf("%d", &arr[i]);
}

float average(int arr[]) {
    int summ = 0;
    for (int i = 0; i < SZ; i++)
    {
        summ += arr[i];
    }
    return (float)summ/SZ;
}
