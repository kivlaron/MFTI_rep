// Составить рекурсивную функцию, печать всех простых множителей числа.
#include <stdio.h>

void divPrint(unsigned int num);

int main(int argc, char **argv)
{
    unsigned int n;
    scanf("%d", &n);
    divPrint(n);
}

void divPrint(unsigned int num) {
    unsigned int del = 2;
    while (num%del != 0) {
        del ++;
        if (del == num) {
            printf("%d", del);
            return;
        }
        if (del > num)
            return;
    }
    printf("%d ", del);
    divPrint(num/del);
}
