// Дана последовательность ненулевых целых чисел, завершающаяся
// числом 0. Ноль в последовательность не входит. Определите наибольшее
// значение числа в этой последовательности. Для решения задачи
// необходимо написать рекурсивную функцию вида:
// int max_find(int max)
#include <stdio.h>

int max_find(int max);

int main(int argc, char **argv)
{
    printf("%d", max_find(-32765));
}

int max_find(int max) {
    int num;
    scanf("%d", &num);
    if (num == 0)
        return max;
    if (max < num)
        return max_find(num);
    else
        return max_find(max);
}
