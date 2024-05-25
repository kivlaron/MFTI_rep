// Переставить цифры в числе так, что бы получилось максимальное число.
#include <stdio.h>

void sort(unsigned char arr[], unsigned char count);
unsigned int collect(unsigned char arr[], unsigned char count);

int main(void)
{
    unsigned int n;
    unsigned char arr[10], ind = 0;
    scanf("%d", &n);
    do {
        arr[ind++] = n%10;
        n /= 10;
    } while (n != 0);
    sort(arr, ind);
    printf("\n%d", collect(arr, ind));
}

void sort(unsigned char arr[], unsigned char count) {
    int temp;
    for (int i = 0; i < count; i ++) {
        for (int j = i + 1; j < count; j ++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

unsigned int collect(unsigned char arr[], unsigned char count) {
    unsigned int res = 0, digit = 1;
    for (int i = 0; i < count; i++) {
        res += arr[i]*digit;
        digit *= 10;
    }
    return res;
}
