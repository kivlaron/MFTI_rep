//Составить функцию логическую функцию, которая определяет, верно ли,
//что в заданном числе все цифры стоят по возрастанию. Используя данную
//функцию решить задачу. int grow_up(int n)
#include <stdio.h>

int growUp(int n);

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    if (n >= 0)
        printf(growUp(n) == 0 ? "NO" : "YES");
}

int growUp(int n) {
    if (n == 0)
        return 1;
    int prev = n%10;
    n /= 10;
    do {
        if (n%10 >= prev)
            return 0;
        prev = n%10;
        n /= 10;
    } while (n != 0);
    return 1;
}
