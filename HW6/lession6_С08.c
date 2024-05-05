#include <stdio.h>

char caps(char c);

int main(int argc, char **argv)
{
    char c;
    while ((c = getchar()) != '.')
        putchar(caps(c));
}

char caps(char c) {
    if ((c >= 'a') && (c <= 'z'))
        c = c - 0x20;
    return c;
}
