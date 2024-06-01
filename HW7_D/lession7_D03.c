//Дано целое не отрицательное число N. Выведите все его цифры по одной,
//в обратном порядке, разделяя их пробелами или новыми строками.
//Составить рекурсивную функцию.
#include <stdio.h>

int printRev(int n);

int main(int argc, char **argv)
{
    int n;

    scanf("%d", &n);
    if (n >= 0)
        printf("%d", printRev(n));
}

int printRev(int n) {
    if (n < 10) {
        return n;
    }
    printf ("%d ", n%10);
    return printRev(n/10);
}
