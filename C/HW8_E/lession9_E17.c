// Дан массив из 10 элементов. В массиве найти элементы, которые в нем
// встречаются только один раз, и вывести их на экран.
#include <stdio.h>

const unsigned int SZ = 10;

void inputArr(int arr[]);
void onceOccursNumPrint(int arr[]);

int main(void)
{
    int arr[SZ];
    inputArr(arr);
    onceOccursNumPrint(arr);
    return 0;
}

void inputArr(int arr[]) {
    for (int i = 0; i < SZ; i ++) {
        scanf("%d", &arr[i]);
    }
}

void onceOccursNumPrint(int arr[]) {
    for (int i = 0; i < SZ; i++) {
        int j;
        for (j = 0; j < SZ; j ++)
            if ((i != j) &&(arr[i] == arr[j]))
                break;
        //printf("arr[%d] = %d, arr[%d] = %d\n", i, arr[i], j, arr[j]);
        if (j == SZ)
            printf("%d ", arr[i]);
    }
}
