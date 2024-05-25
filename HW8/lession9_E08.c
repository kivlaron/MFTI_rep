// Считать массив из 12 элементов и выполнить инверсию для каждой
// трети массива.
#include <stdio.h>

const int SZ = 12;

void inputArr(int arr[]);
void outputArr(int arr[]);
void permutation(int arr[]);

int main(void)
{
    int arr[SZ];
    inputArr(arr);
    permutation(arr);
    outputArr(arr);
    return 0;
}

void inputArr(int arr[]) {
    for (int i = 0; i < SZ; i ++)
        scanf("%d", &arr[i]);
}

void outputArr(int arr[]) {
    for (int i = 0; i < SZ; i++)
        printf("%d ", arr[i]);
}
void permutation(int arr[]) {
    int temp[SZ/3], indTemp;
    for (int j = SZ/3; j <= SZ; j += SZ/3)
    {
        indTemp = 0;
        for (int i = j - SZ/3; i < j; i++)
        {
            temp[indTemp++] = arr[i];
        }
        indTemp = SZ/3 - 1;
        for (int i = j - SZ/3; i < j; i++)
        {
            arr[i] = temp[indTemp--];
        }
    }
}
