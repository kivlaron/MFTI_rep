// Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.
#include <stdio.h>

const int SZ = 5;

void inputArr(int arr[]);
int minEl(int arr[]);

int main(void)
{
    int arr[SZ];
    inputArr(arr);
    printf("%d", minEl(arr));
    return 0;
}

void inputArr(int arr[]) {
    for (int i = 0; i < SZ; i ++)
        scanf("%d", &arr[i]);
}

int minEl(int arr[]) {
    int min = arr[0];
    for (int i = 1; i < SZ; i++)
    {
        min = min > arr[i] ? arr[i] : min;
    }
    return min;
}
