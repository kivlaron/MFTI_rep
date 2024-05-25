// Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО
// на 4 элемента.
#include <stdio.h>

const int SZ = 12;

void inputArr(int arr[]);
void outputArr(int arr[]);
void shift(int arr[]);

int main(void)
{
    int arr[SZ];
    inputArr(arr);
    shift(arr);
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
void shift(int arr[]) {
    for (int j = 1; j <= 4; j ++) {
        int temp = arr[SZ - 1];
        for (int i = SZ - 1; i > 0; i --)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
}
