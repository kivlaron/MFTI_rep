// В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)в произвольном порядке, но одно из чисел
// пропущено (остальные встречаются ровно по одному разу). N не превосходит 1000. Последовательность заканчивается числом 0.
// Определить пропущенное число.

#include <stdio.h>

const int SIZE = 1000;

int max(int a[]);
int min(int a[]);
void inputArr (int a[], int sz);

int main(int argc, char **argv)
{
    int a[SIZE];
    int arr_size, start, end, j;
    inputArr (a, SIZE);
    start = min(a);
    end = max(a);
    arr_size = end - start;
    for (int i = 0; i < arr_size; i ++) {
        for (j = 0; j < arr_size; j ++) {
            if (a[j] == start) {
                break;
            }
        }
        if (j == arr_size)
            printf("%d ", start);
        start ++;
    }
    return 0;
}

int max(int a[]) {
    int max = a[0], i = 0;
    do {
        max = (a[i] > max) ? a[i] : max;
    } while (a[++i] != 0);
    return max;
}

int min(int a[]) {
    int min = a[0], i = 0;
    do {
        min = (a[i] < min) ? a[i] : min;
    } while (a[++i] != 0);
    return min;
}

void inputArr (int a[], int sz) {
    int inp, i = 0;
    do {
        scanf("%d", &inp);
        if ((inp <= 1000) && (inp >= 1)) {
            a[i++] = inp;
        }
    } while (inp != 0);
    a[i] = 0;
}
