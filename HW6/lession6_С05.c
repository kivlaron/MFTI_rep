#include <stdio.h>

int summ(int n);

int main(int argc, char **argv)
{
    int n;

    scanf("%d", &n);
    printf("%d", summ(n));
}

int summ(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += i;
    return sum;
}

