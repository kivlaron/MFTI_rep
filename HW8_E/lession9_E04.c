// Считать массив из 10 элементов и найти в нем два максимальных
// элемента и напечатать их сумму.
#include <stdio.h>

const int SZ = 10;

void inputArr(int arr[]);
int maxNumIndex(int arr[], int ind);

int main(void)
{
    int arr[SZ];
    inputArr(arr);
    int ind_max_element_1 = maxNumIndex(arr, -1);
    int ind_max_element_2 = maxNumIndex(arr, ind_max_element_1);
    printf("%d", arr[ind_max_element_1] + arr[ind_max_element_2]);
    return 0;
}

void inputArr(int arr[]) {
    for (int i = 0; i < SZ; i ++)
        scanf("%d", &arr[i]);
}

int maxNumIndex(int arr[], int ind) {
    int max_index;
    max_index = ind == 0 ? 1 : 0;
    for (int i = 1; i < SZ; i++)
    {
        if(i != ind) {
            max_index = arr[max_index] < arr[i] ? i : max_index;
        }
    }
    return max_index;
}
