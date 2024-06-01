// Считать массив из 10 элементов и отсортировать первую половину
// по возрастанию, а вторую – по убыванию.
#include <stdio.h>

const int SZ = 10;

void inputArr(int arr[]);
void outputArr(int arr[]);
void sort(int arr[]);

int main(void)
{
    int arr[SZ];
    inputArr(arr);
    sort(arr);
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

void sort(int arr[]) {
    for (int i = 0; i < SZ/2; i ++) {
        for (int j = i; j < SZ/2; j ++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = SZ/2; i < SZ; i ++) {
        for (int j = i; j < SZ; j ++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
