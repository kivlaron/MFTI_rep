//Составить рекурсивную функцию, печать всех чисел от 1 до N
#include <stdio.h>

int printNums(int n);

int main(int argc, char **argv)
{
    int n;

    scanf("%d", &n);
    printf("%d", printNums(n));
}

int printNums(int n) {
    if (n == 1)
        return n;
    printf("%d ", printNums(n - 1));
    return n;
}
