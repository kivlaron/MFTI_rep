// Вывести в порядке следования цифры, входящие в десятичную запись
// натурального числа N.
#include <stdio.h>

int main(void)
{
    unsigned int n;
    unsigned char arr[10], ind = 0;
    scanf("%d", &n);
    do {
        arr[ind++] = n%10;
        n /= 10;
    } while (n != 0);
    for (int i = ind - 1; i >= 0; i --)
        printf("%d ", arr[i]);
}
