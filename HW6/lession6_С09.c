#include <stdio.h>

int fac(int n);

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    if ((n >= 0) && (n <= 20))
        printf("%d", fac(n));
}

int fac(int n) {
    if (n == 0)
        return 0;
    int res = 1;
    for (int i = 2; i <= n; i ++)
        res *= i;
    return res;
}
