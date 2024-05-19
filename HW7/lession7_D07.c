// Составить рекурсивную функцию, печать всех чисел от N до 1.
#include <stdio.h>

void printNums(int n);

int main(int argc, char **argv)
{
    unsigned int n;
    scanf("%d", &n);
    printNums(n);
}

void printNums(int n) {
    printf("%d ", n);
    if (n > 1)
        printNums(n - 1);
}
