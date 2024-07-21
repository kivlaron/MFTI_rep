// В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
// Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.

#include <stdio.h>
#include <string.h>

_Bool is_exist(char str[], char c);

int main(void)
{
    FILE *f;
    char str[1000] = {0}, c;
    unsigned int i = 0;

    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        while ((c = fgetc(f)) != EOF)
        {
            if ((c != '\n') && (c != ' '))
            {
                if (!is_exist(str, c))
                {
                    str[i++] = c;
                }
            }
        }
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    f = fopen("output.txt", "w");
    if (f != NULL)
    {
        for (size_t i = 0; i < strlen(str); i++)
        {
            fprintf(f, "%c", str[i]);
        }
    }
    else
    {
        printf("Can`t open file output.txt");
    }
    fclose(f);
    return 0;
}

_Bool is_exist(char str[], char c)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (c == str[i])
            return 1;
    }
    return 0;
}