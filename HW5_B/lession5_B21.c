#include <stdio.h>
#include <stdint.h>

int main (void) {
    char c;

    while ((c = getchar()) != '.') {
        if ((c >= 65) && (c <= 90))
            c += 32;
        putchar(c);
    }
}
