//Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N
#include <stdio.h>

int sumNums(int n);

int main(int argc, char **argv)
{
    int n;

    scanf("%d", &n);
    printf("%d", sumNums(n));
}

int sumNums(int n) {
    if (n == 1)
        return n;
    return n + sumNums(n - 1);
}
