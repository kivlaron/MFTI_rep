// В диапазоне натуральных чисел от 2 до N определить, сколько из них
// кратны любому из чисел в диапазоне от 2 до 9.
#include <stdio.h>

int main(void)
{
    unsigned int n, count;
    scanf("%d", &n);
    if ((n >= 2) && (n <= 10000)) {
        for (int i = 2; i <= 9; i++) {
            count = 0;
            for (int j = 2; j <= n; j ++) {
                if (j%i == 0)
                    count ++;
            }
            printf("%d %d\n", i, count);
        }
    }
}
