// Дана монотонная последовательность, в которой каждое натуральное
// число k встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,…
// Выведите первые n членов этой последовательности.
// Только один цикл for.
#include <stdio.h>

void sequence(unsigned int k, unsigned int num);

int main(int argc, char **argv)
{
    unsigned int n, sum = 0;
    scanf("%d", &n);
    for (unsigned int i = 1; i <= n; i ++) {
        sequence(sum + i < n ? i : n - sum, i);
        if (sum + i >= n)
            break;
        sum += i;
    }
}

void sequence(unsigned int k, unsigned int num) {
    if (k > 1)
        sequence(k - 1, num);
    printf("%d ", num);
}
