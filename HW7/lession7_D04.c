// Дано натуральное число N. Выведите все его цифры по одной, в прямом
// порядке, разделяя их пробелами или новыми строками. Необходимо
// реализовать рекурсивную функцию.
// void print_num(int num)
#include <stdio.h>

void print_num(int num);

int main(int argc, char **argv)
{
    int n;

    scanf("%d", &n);
    if (n >= 0)
        print_num(n);
}

void print_num(int num) {
    if (num < 10) {
        printf ("%d ", num);
    } else {
        print_num(num/10);
        printf ("%d ", num - (num/10)*10);
    }
}
