// Считать массив из 10 элементов и выделить в другой массив все числа,
// которые встречаются более одного раза. В результирующем массиве эти
// числа не должны повторяться.
#include <stdio.h>

const int SZ = 10;

void inputArr(int arr[]);
void outputArr(int arr[], int count);
void select(int arr[], int arr2[], int *count);
char isNotBelong(int arr[], int elem, int length_arr);

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
    for (int i = 0; i < length_arr; i ++)
        printf("%d ", arr[i]);
}

void select(int arr[], int arr2[], int *count) {
    for (int i = 0; i < SZ; i ++) {
        int temp = arr[i];
        for (int j = i + 1; j < SZ; j ++) {
            if ((temp == arr[j]) && (isNotBelong(arr2, temp, *count)))
                arr2[(*count) ++] = temp;
        }
    }
}

char isNotBelong(int arr[], int elem, int length_arr) {
    for (int i = 0; i < length_arr; i++) {
        if (arr[i] == elem)
            return 0;
    }
    return 1;
}
