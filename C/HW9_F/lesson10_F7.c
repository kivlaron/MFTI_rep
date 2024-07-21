// Написать функцию, которая сжимает серии массива, состоящего из единиц и нулей по следующему принципу: например,
// массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1] преобразуется в [4,7,2,4] (т.к. начинается с нуля, то сразу записывается количество элементов
// первой серии); а массив [1,1,1,0,0,0,0,0,0,0] преобразуется в [0,3,7] (т.к. первая серия - это единицы, то первый элемент преобразованного
// массива 0).
// Необходимо реализовать только одну функцию, всю программу загружать не надо. Прототип функции: int compression(int a[], int b[], int N)

#include <stdio.h>

int compression(int a[], int b[], int N);

int main(int argc, char **argv)
{
    int a[] = {1,1,1,0,0,0,0,0,0,0}, b[] = {0}, a_size, b_size;
    a_size = sizeof(a) / sizeof(a[0]);
    printf("[");
    for (int i = 0; i < a_size; i++)
    {
        printf(" %d,", a[i]);
    }
    printf("]");
    printf("\n------->\n");
    b_size = compression(a, b, a_size);
    printf("[");
    for (int i = 0; i < b_size; i++)
    {
        printf(" %d,", b[i]);
    }
    printf("]");
    return 0;
}

int compression(int a[], int b[], int N)
{
    int count = 0, b_index = 0, marker_of_1 = 0;
    for (int i = 0; i < N; i++) {
        if (marker_of_1 != a[i]) {
            b[b_index++] = count;
            count = 1;
        } else {
            count ++;
        }
        marker_of_1 = a[i];
    }
    b[b_index] = count;
    return b_index + 1;
}