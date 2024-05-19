// Написать логическую рекурсивную функцию и используя ее определить
// является ли введенное натуральное число точной степенью двойки.
// int is2pow(int n)
#include <stdio.h>

int is2pow(int n);

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    is2pow(n) == 0 ? printf("YES") : printf("NO");
}

int is2pow(int n) {
    if(n == 1)
        return 0;
    if(n%2 != 0)
        return 1;
    return is2pow(n/2);
}
