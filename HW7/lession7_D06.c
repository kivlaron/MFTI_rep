// Дана строка заканчивающаяся символом точка '.' Напечатать строку
// наоборот. Реализуйте рекурсивную функцию, которая считывает и
// печатает строку наоборот.
// void reverse_string()
#include <stdio.h>

void reverse_string();

int main(int argc, char **argv)
{
    reverse_string();
}

void reverse_string() {
    char c = getchar();
    if (c != '.') {
        reverse_string();
        putchar(c);
    }

}
