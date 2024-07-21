// Дано натуральное число N. Посчитать количество «1» в двоичной записи
// числа. Составить рекурсивную функцию.
#include <stdio.h>

int one_qty(int n);

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    printf("%d", one_qty(n));
}

int one_qty(int n) {
    int sum = 0;
    if (n > 1)
        sum += one_qty(n/2);
    return sum + n%2;
}
