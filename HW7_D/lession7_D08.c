// Составить рекурсивную функцию, Выведите все числа от A до B
// включительно, в порядке возрастания, если A < B, или в порядке
// убывания в противном случае.
#include <stdio.h>

void printNums2(int a, int b);

int main(int argc, char **argv)
{
    int a, b;
    scanf("%d%d", &a, &b);
    printNums2(a, b);
}

void printNums2(int a, int b) {
    if (a < b) {
        printf("%d ", a);
        printNums2(a + 1, b);
    }
    if (a > b) {
        printf("%d ", a);
        printNums2(a - 1, b);
    }
    if (a == b)
        printf("%d", a);
}
