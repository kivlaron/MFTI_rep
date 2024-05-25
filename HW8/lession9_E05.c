// Считать массив из 10 элементов и посчитать сумму положительных
// элементов массива.
#include <stdio.h>

const int SZ = 10;

void inputArr(int arr[]);
int posSumm(int arr[]);

int main(void)
{
    int arr[SZ];
    inputArr(arr);
    printf("%d", posSumm(arr));
    return 0;
}

void inputArr(int arr[]) {
    for (int i = 0; i < SZ; i ++)
        scanf("%d", &arr[i]);
}

int posSumm(int arr[]) {
    int pos_summ = 0;
    for (int i = 0; i < SZ; i++)
    {
        pos_summ += arr[i] > 0 ? arr[i] : 0;
    }
    return pos_summ;
}
