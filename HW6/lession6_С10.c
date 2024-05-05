#include <stdio.h>

void print_simple(int n);

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    if (n >= 0)
        print_simple(n);
}

void print_simple(int n) {
    if ((n == 0) || (n == 1))
        printf("%d ", n);
    do {
        for (int i = 2; i <= n; i ++)
            if (n%i == 0) {
                printf("%d ", i);
                n /= i;
                break;
            }
    } while (n != 1);
}
