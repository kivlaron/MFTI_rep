//Мудрец попросил у Повелителя за первую клетку шахматной доски
//заплатить ему одно зерно риса, за второе — два, за третье — четыре и
//т. д., удваивая количество зёрен на каждой следующей клетке. Помоги
//повелителю сосчитать сколько зерен на какой клетке лежит.
//Необходимо составить функцию, которая определяет, сколько зерен
//попросил положить на N-ую клетку изобретатель шахмат
//(на 1-ую – 1 зерно, на 2-ую – 2 зерна, на 3-ю – 4 зерна, …)
#include <stdio.h>
#include <stdint.h>

//unsigned long long summ(int n);
uintmax_t summ(int n);

int main(int argc, char **argv)
{
    int n;

    scanf("%d", &n);
    printf("%lu", summ(n));
}

//unsigned long long summ(int n) {
uintmax_t summ(int n) {
    if (n == 0)
        return 0;
    uintmax_t sum = 1;
    for (int i = 2; i <= n; i ++)
        sum *= 2;
    return sum;
}
