// Дано натуральное число n ≥ 1. Проверьте, является ли оно простым.
// Программа должна вывести слово YES, если число простое или NO в
// противном случае. Необходимо составить рекурсивную функцию и
// использовать ее.
// int is_prime(int n, int delitel)
#include <stdio.h>

int is_prime(int n, int delitel);

int main(int argc, char **argv)
{
    int n, delitel = 2;
    scanf("%d", &n);
    is_prime(n, delitel) == 0 ? printf("NO") : printf("YES");
}

int is_prime(int n, int delitel) {
    if (n == 1)
        return 0;
    if (delitel >= n)
        return 1;
    else if (n%delitel == 0)
        return 0;
    if (is_prime(n, delitel + 1) == 0)
        return 0;
    return 1;
}
