// Написать только одну функцию. Всю программу отправлять не надо.
// Вывести в порядке возрастания цифры, входящие в строку.
// Цифра - количество. Функция должно строго соответствовать прототипу:
// void print_digit(char s[])

#include <stdio.h>

void print_digit(char s[]);

int main(int argc, char **argv)
{
    char s[1000];
    int index = 0;
    while ((s[index++] = getchar()) != '\n');
    print_digit(s);
}

void print_digit(char s[]) {
    int index = 0;
    int quant[10] = {0};
    while (s[index] != '\0') {
        if ((s[index] >= 48) && (s[index] <= 57))
            quant[s[index] - 48]++;
        index ++;
    }
    for (int i = 0; i < 10; i ++)
        if (quant[i] != 0)
            printf("%d %d\n", i, quant[i]);
}
