#include <stdio.h>

void bracketsCheck(void);

int main(int argc, char **argv)
{
    bracketsCheck();
}

void bracketsCheck(void) {
    int open_bracket_count = 0, close_bracket_count = 0;
    char c;
    while ((c = getchar()) != '.') {
        if (c == '(')
            open_bracket_count ++;
        if (c == ')')
            close_bracket_count ++;
        if (close_bracket_count > open_bracket_count) {
            puts("NO");
            return;
        }
    }
    printf(open_bracket_count == close_bracket_count ? "YES" : "NO");
}
