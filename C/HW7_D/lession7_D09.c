// Дано натуральное число N. Вычислите сумму его цифр. Необходимо
// составить рекурсивную функцию.
// int sum_digits(int n)
#include <stdio.h>

int sum_digits(int n);

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    printf("%d", sum_digits(n));
}

int sum_digits(int n) {
    if (n < 10)
        return n;
    return n%10 + sum_digits(n/10);
}
