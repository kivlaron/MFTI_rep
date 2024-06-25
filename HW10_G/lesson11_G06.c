// В файле input.txt символьная строка не более 1000 символов.
// Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях).
// Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.

#include <stdio.h>
#include <string.h>

void is_palindrom(char str[]);

int main(void)
{
    FILE *fr;
    char str[1000], c;
    int i = 0;

    fr = fopen("input.txt", "r");
    if ((fr != NULL) && (fr != NULL))
    {
        while ((c = fgetc(fr)) != EOF)
        {
            if (c != '\n')
            {
                str[i++] = c;
            }
        }
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(fr);
    str[i] = '\0';
    is_palindrom(str);
    return 0;
}

void is_palindrom(char str[])
{
    FILE *fw;
    fw = fopen("output.txt", "w");
    int s_len = strlen(str);
    if (fw != NULL)
    {
        if (s_len == 1)
        {
            fprintf(fw, "YES");
            fclose(fw);
            return;
        }
        for (size_t i = 0; i < s_len / 2; i++)
        {
            if (str[i] != str[s_len - i - 1])
            {
                fprintf(fw, "NO");
                fclose(fw);
                return;
            }
        }
        fprintf(fw, "YES");
    }
    else
    {
        printf("Can`t open file output.txt");
    }
    fclose(fw);
}