#include <stdio.h>

int isHappyNumber(int n);

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    if (n >= 0)
        printf(isHappyNumber(n) == 0 ? "NO" : "YES");
}

int isHappyNumber(int n) {
    int sum = 0, mul = 1;
    do {
        sum += n%10;
        mul *= n%10;
        n /= 10;
    } while (n != 0);
    return sum == mul ? 1 : 0;
}
