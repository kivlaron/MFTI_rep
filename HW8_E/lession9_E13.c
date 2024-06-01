// Считать массив из 10 элементов и отобрать в другой массив все числа,
// у которых вторая с конца цифра (число десятков) – ноль.
#include <stdio.h>

const int SZ = 10;

void inputArr(int arr[]);
void outputArr(int arr[], int count);
void select(int arr[], int arr2[], int *count);

int main(void)
{
    int arr[SZ], arr2[SZ], count = 0;
    inputArr(arr);
    select(arr, arr2, &count);
    outputArr(arr2, count);
    return 0;
}

void inputArr(int arr[]) {
    for (int i = 0; i < SZ; i ++)
        scanf("%d", &arr[i]);
}

void outputArr(int arr[], int length_arr) {
    for (int i = 0; i < length_arr; i++)
        printf("%d ", arr[i]);
}

void select(int arr[], int arr2[], int *count) {
    for (int i = 0; i < SZ; i ++) {
        //if (arr[i]/10 != 0) //checking if the number does not have tens
        if ((arr[i]/10)%10 == 0) {
            arr2[(*count) ++] = arr[i];
        }
    }
}
