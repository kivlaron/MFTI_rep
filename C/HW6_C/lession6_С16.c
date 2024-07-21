//Составить функцию логическую функцию, которая определяет, верно ли,
//что число простое. Используя функцию решить задачу.
#include <stdio.h>

int isPrime(int n);

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    if (n >= 0)
        printf(isPrime(n) == 0 ? "NO" : "YES");
}

int isPrime(int n) {
    if ((n == 0) || (n == 1))
        return 0;
    for (int i = 2; i < n; i ++)
        if (n%i == 0)
            return 0;
    return 1;
}


