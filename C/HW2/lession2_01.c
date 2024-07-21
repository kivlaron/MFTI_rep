#include <stdio.h>

int main(int argc, char **argv)
{
int a, b;

printf ("-------------\n");
printf ("a | b | !a||b\n");
printf ("-------------\n");
for (a = 0; a <= 1; a ++) {
    for (b = 0; b <= 1; b ++) {
        printf ("%d", a);
        printf (" | ");
        printf ("%d", b);
        printf (" | ");
        printf ("%u\n", !(a&1) || (b&1));
        printf ("-------------\n");
    }
}
}

