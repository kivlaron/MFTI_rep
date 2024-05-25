// Считать массив из 10 элементов и выполнить инверсию отдельно
// для 1-ой и 2-ой половин массива. Необходимо изменить считанный
// массив и напечатать его одним циклом.
#include <stdio.h>

const int SZ = 10;

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
    int temp, lim = SZ/2;
    for (int i = 0; i < lim/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[lim - i - 1];
        arr[lim - i - 1] = temp;
    }
    for (int i = lim; i < SZ - lim/2 - 1; i++)
    {
        temp = arr[i];
        arr[i] = arr[SZ - i + lim - 1];
        arr[SZ - i + lim - 1] = temp;
    }
}
