// Дан целочисленный массив из 10 элементов. Необходимо определить количество четных и нечетных чисел.
// Если количество чётных чисел больше, чем количество нечётных, заменить каждое нечетное число на произведение нечетных цифр в его десятичной записи.
// Если количество нечётных чисел больше или равно количеству чётных, заменить каждое чётное число на произведение чётных цифр в его десятичной записи.

#include <stdio.h>

const int SIZE = 10;

void print_a(int a[]);
void change_a(int a[], _Bool condition);
int odd_mult(int num);
int even_mult(int num);

int main(int argc, char **argv)
{
    int a[SIZE], even = 0, odd = 0;
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &a[i]);
        a[i] % 2 == 0 ? even++ : odd++;
    }
    if (even > odd)
        change_a(a, 1);
    if (odd >= even)
        change_a(a, 0);
    print_a(a);
}

void print_a(int a[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", a[i]);
    }
}

void change_a(int a[], _Bool condition)
{
    for (int i = 0; i < SIZE; i++)
    {
        if ((a[i] % 2 != 0) && (condition == 1)) // even more
        {
            a[i] = odd_mult(a[i]);
        }
        if ((a[i] % 2 == 0) && (condition == 0)) // odd more
        {
            a[i] = even_mult(a[i]);
        }
    }
}

int odd_mult(int num)
{
    int n, res = 1;
    do {
        n = num%10;
        if (n%2 != 0)
            res *= n;
        num /= 10;
    } while (num != 0);
    return res;
}

int even_mult(int num)
{
    int n, res = 1;
    do {
        n = num%10;
        if (n%2 == 0)
            res *= n;
        num /= 10;
    } while (num != 0);
    return res;
}