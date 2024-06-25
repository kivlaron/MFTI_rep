// Считать предложение из файла input.txt и определить можно ли из английских букв предложения записанного в файле получить одно слово - палиндром.
// Ответ напечатать на стандартный поток вывода. Требуется реализовать логическую функцию и применить ее.
// is_palindrom(string)

#include <stdio.h>
#include <string.h>

_Bool is_palindrom(char str[]);
void readFromFile(char str[]);

int main(void)
{
    char str[1000] = {0};
    readFromFile(str);
    is_palindrom(str) == 1 ? printf("YES") : printf("NO");
    return 0;
}

void readFromFile(char str[])
{
    FILE *f;
    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        fscanf(f, "%[^EOF]", str);
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
}

_Bool is_palindrom(char str[])
{
    int count = strlen(str), couples_count = 0;
    char zero_symbol = 0x7F;
    for (size_t i = 0; i < count; i++)
    {
        if (str[i] == zero_symbol)
            continue;
        for (size_t j = 0; j < count; j++)
        {
            if (i != j)
            {
                if ((str[i] >= 'a') || (str[i] <= 'z'))
                {
                    if (str[i] == str[j])
                    {
                        str[i] = zero_symbol;
                        str[j] = zero_symbol;
                        break;
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < count; i++)
    {
        if ((str[i] >= 'a') && (str[i] <= 'z'))
        {
            couples_count++;
        }
    }
    if (couples_count > 1) {
        return 0;
    } else {
        return 1;
    }
}