// Дан массив из 10 элементов. Определить, какое число в массиве
// встречается чаще всего. Гарантируется, что такое число ровно 1.
#include <stdio.h>

const unsigned int SZ = 10;

void inputArr(int arr[]);
int frequentNumber(int arr[]);

int main(void)
{
    int arr[SZ];
    inputArr(arr);
    printf("%d", frequentNumber(arr));
    return 0;
}

void inputArr(int arr[]) {
    for (int i = 0; i < SZ; i ++) {
        scanf("%d", &arr[i]);
    }
}

int frequentNumber(int arr[]) {
    int res = 0, count_temp = 1, max_count = 0;
    for (int i = 0; i < SZ; i++) {
        for (int j = i + 1; j < SZ; j ++) {
            if (arr[i] == arr[j]) {
                count_temp ++;
            }
        }
        if (count_temp > max_count) {
            max_count = count_temp;
            res = arr[i];
        }
        count_temp = 1;
    }
    return res;
}
