// В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
// Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
// Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести массив по возрастанию в файл output.txt.

#include <stdio.h>
#include <stdlib.h>

int sort_number (const void *a, const void *b);

int main(void)
{
    FILE *f;
    char str[1000], c;
    int nums[1000] = {0}, ind = 0, order_num = 0;
    _Bool is_number = 0;

    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        while ((c = fgetc(f)) != EOF)
        {
            if (c != '\n')
            {
                if ((c >= '0') && (c <= '9')) {
                    nums[ind] = 10*nums[ind] + (c - '0');
                    is_number = !is_number ? 1 : is_number;
                } else {
                    if (is_number) {
                        ind ++;
                        is_number = 0;
                    }
                }
            }
        }
        if (is_number)   // numder is the last symbol
            ind ++;
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    qsort(nums, ind, sizeof(int), sort_number);
    f = fopen("output.txt", "w");
    if (f != NULL)
    {
        for (size_t i = 0; i < ind; i++)
        {
            fprintf (f, "%d ", nums[i]);
        }
    }
    else
    {
        printf("Can`t open file output.txt");
    }
    fclose(f);
    return 0;
}

int sort_number (const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y;
}