#include <stdio.h>

int f(int x);

int main(int argc, char **argv)
{
    int x, max;

    scanf("%d", &x);
    if (x == 0)
        return 0;
    max = f(x);
    do {
        scanf("%d", &x);
        if (x == 0)
            break;
        max = max < f(x) ? f(x) : max;
    } while (1);
    printf("%d", max);
}

int f(int x) {
    if ((x >= -2) && (x < 2))
        return x*x;
    else if (x >= 2)
        return x*x + 4*x + 5;
    else
        return 4;
}

