// Ввести c клавиатуры массив из 5 элементов, найти среднее
// арифметическое всех элементов массива.
#include <stdio.h>

int main(void)
{
    const int SZ = 5;
    int arr[SZ], sum = 0;
    for (int i = 0; i < SZ; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("%.3f", (float)sum/(sizeof(arr)/sizeof(arr[0])));
    return 0;
}
