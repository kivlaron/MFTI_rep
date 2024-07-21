#include <stdio.h>

int abs_func (int num);

int main(int argc, char **argv)
{
    int num;

    scanf("%d", &num);
    printf ("%d", abs_func (num));
    return 0;
}

int abs_func (int num) {
    return num > 0 ? num : -num;
}

