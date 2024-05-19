// Дана последовательность целых чисел через пробел, завершающаяся
// числом 0. Выведите все нечетные числа из этой последовательности,
// сохраняя их порядок. Составить рекурсивную функцию.
#include <stdio.h>

void notEvenPrint(void);

int main(int argc, char **argv)
{
    notEvenPrint();
}

void notEvenPrint(void) {
    int num;
    scanf("%d", &num);
    if (num == 0)
        return;
    if (num%2 != 0)
        printf("%d ", num);
    notEvenPrint();
}
