#include <stdio.h>

int power(int n, int p);

int main(int argc, char **argv)
{
    int num, pow;

    scanf("%d%d", &num, &pow);
    printf("%d", power(num, pow));
    return 0;
}

int power(int n, int p) {
    int res = 1;
    if (p == 0)
        return 1;
    for (int i = 1; i <= p; i ++)
        res *= n;
    return res;
}

