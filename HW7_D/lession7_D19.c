// Дана строка из английских символов, пробелов и знаков препинания.
// В конце строки символ точка. Необходимо реализовать рекурсивную
// функцию, которая считывает данную строку со стандартного потока
// ввода и возвращает целое число - количество символов 'a' в данной
// строке.
// int acounter(void)
// Используя данную функцию решить задачу.
#include <stdio.h>

int acounter(void);

int main(int argc, char **argv)
{
    printf("%d", acounter());
}

int acounter(void) {
    char c;
    while ((c = getchar()) != '.')
        return (c == 'a') + acounter();
    return 0;
}