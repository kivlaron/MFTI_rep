// Написать рекурсивную функцию возведения целого числа n в степень p.
// int recurs_power(int n, int p)
// Используя данную функцию, решить задачу.
#include <stdio.h>

int recurs_power(int n, int p);

int main(int argc, char **argv)
{
    int n, p;
    scanf("%d%d", &n, &p);
    if ((n >= -100) && (n <= 100) && (p >= 0) && (p <= 100)) {
        printf("%d", recurs_power(n, p));
    }
}

int recurs_power(int n, int p) {
    if (p <= 0)
        return 1;
    return recurs_power(n, p - 1)*n;
}
