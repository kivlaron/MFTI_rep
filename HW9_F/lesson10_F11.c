// Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int.
// Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна.
#include <stdio.h>
#include <stdlib.h>

const int SIZE = 30;

void min_summ_elements(int a[]);
void input_a(int a[]);

int main(int argc, char **argv)
{
    int a[SIZE];
    input_a(a);
    min_summ_elements(a);
}

void min_summ_elements(int a[]) {
    int ind1 = 0, ind2 = 1;
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j ++) {
            if (i != j) {
                if (a[ind1] + a[ind2] > a[i] + a[j]) {
                    ind1 = i;
                    ind2 = j;
                }
            }
        }
    }
    ind1 < ind2 ? printf("%d %d", ind1, ind2) : printf("%d %d", ind2, ind1);
}

void input_a(int a[]) {
    for (int i = 0; i < SIZE; i ++) {
        scanf("%d", &a[i]);
    }
}