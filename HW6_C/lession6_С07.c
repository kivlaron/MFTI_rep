//Когда создатель шахмат, древнеиндийский мудрец и математик Сисса бен
//Дахир, показал своё изобретение Правителю страны, тому так понравилась
//игра, что он позволил изобретателю право самому выбрать награду.
//Мудрец попросил у Повелителя за первую клетку шахматной доски
//заплатить ему одно зерно риса, за второе — два, за третье — четыре и
//т. д., удваивая количество зёрен на каждой следующей клетке. Помоги
//повелителю сосчитать сколько зерен на какой клетке лежит.
//Необходимо составить функцию, которая определяет, сколько зерен
//попросил положить на N-ую клетку изобретатель шахмат
//(на 1-ую – 1 зерно, на 2-ую – 2 зерна, на 3-ю – 4 зерна, …)
#include <stdio.h>
#include <stdint.h>


uint64_t conv(uint32_t n, uint8_t p);

int main(int argc, char **argv)
{
    uint32_t n;
    uint8_t p;

    scanf("%d%hhu", &n, &p);
    if ((n >= 0) && (p >= 2) && (p <= 9))
        printf("%ld", conv(n, p));
}

uint64_t conv(uint32_t n, uint8_t p) {
    uint64_t res = 0, i = 1;
    do {
        res += (n - (n/p)*p)*i;
        n /= p;
        i *= 10;
    } while (n >= p);
    return res + (n - (n/p)*p)*i;
}
