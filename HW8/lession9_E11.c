// Считать массив из 10 элементов и отсортировать его по последней
// цифре.
#include <stdio.h>

const int SZ = 10;

void inputArr(int arr[]);
void outputArr(int arr[]);
void regularize(int arr[]);
char aMoreThanB (int a, int b);

int main(void)
{
    int arr[SZ];
    inputArr(arr);
    regularize(arr);
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
void regularize(int arr[]) {
    int temp;
    for (int i = 0; i < SZ; i ++) {
        int indexMin = i;
        for (int j = i + 1; j < SZ; j ++) {
            if (aMoreThanB(arr[indexMin], arr[j]))
                indexMin = j;
        }
        temp = arr[i];
        arr[i] = arr[indexMin];
        arr[indexMin] = temp;
    }
}

char aMoreThanB (int a, int b) {
    char a_compare, b_compare, a_flag = 0, b_flag = 0;
    do {
        if (a < 10) {
            a_compare = a;
            a_flag = 1;   // in case if compare for exmple: 5 and 555
        } else {
            a_compare = a%10;
            a /= 10;
        }
        if (b < 10) {
            b_compare = b;
            b /= 10;
            b_flag = 1;   // in case if compare for exmple: 5 and 555
        } else {
            b_compare = b%10;
            b /= 10;
        }
        if (a_compare > b_compare)
            return 1;
        if (a_compare < b_compare)
            return 0;
    } while ((a_compare == b_compare) && (a_flag != 1) && (b_flag != 1));
    return 0;
}
