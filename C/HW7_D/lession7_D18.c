// Написать рекурсивную функцию и используя ее решить задачу.
// Напечатать цифры введенного натурального числа в порядке
// следования(слева направо) через пробел.
// void print_digits(int n)
#include <stdio.h>

void print_digits(int n);

int main(int argc, char **argv)
{
    unsigned int n;
    scanf("%d", &n);
    print_digits(n);
}

void print_digits(int n) {
    if(n/10 == 0) {
        printf("%d ", n);
        return;
    }
    print_digits(n/10);
    printf("%d ", n%10);
}
