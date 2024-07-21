// Перевести натуральное число в двоичную систему счисления.
// Необходимо реализовать рекурсивную функцию.
#include <stdio.h>

unsigned int binaryConv(int num);

int main(int argc, char **argv)
{
    unsigned int n;

    scanf("%d", &n);
    binaryConv(n);
}

unsigned int binaryConv(int num) {
    if (num < 2) {
        num == 1 ? printf("1") : printf("0");
        return num;
    }
    printf("%d", num - binaryConv(num/2)*2);
    return num;
}
