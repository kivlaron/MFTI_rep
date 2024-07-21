// Составить функцию которая меняет в массиве минимальный и максимальный элемент местами. Прототип функции void change_max_min(int size, int a[])
#include <stdio.h>
#include <stdlib.h>

void change_max_min(int size, int a[]);
void input_a(int size, int a[]);
void print_a(int size, int a[]);

int main(int argc, char **argv)
{
    int size = 10;
    int a[size];
    input_a(size, a);
    change_max_min(size, a);
    print_a(size, a);
}

void change_max_min(int size, int a[]) {
    int min_i = 0, max_i = 0, temp;
    for (int i = 1; i < size; i ++) {
        min_i = a[i] < a[min_i] ? i : min_i;
        max_i = a[i] > a[max_i] ? i : max_i;
    }
    temp = a[min_i];
    a[min_i] = a[max_i];
    a[max_i] = temp;
}

void input_a(int size, int a[]) {
    for (int i = 0; i < size; i ++) {
        scanf("%d", &a[i]);
    }
}

void print_a(int size, int a[]) {
    for (int i = 0; i < size; i ++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
