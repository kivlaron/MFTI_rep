#include <stdio.h>

int nod(int a, int b);

int main(int argc, char **argv)
{
    int a, b;
    scanf("%d%d", &a, &b);
    if ((a > 0) && (b > 0))
        printf("%d", nod(a, b));
}

int nod(int a, int b) {
    for (int i = (a > b) ? b : a; i >= 2; i --)
        if ((a%i == 0) && (b%i == 0))
            return i;
    return 1;
}
