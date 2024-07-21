// В файле input.txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл output.txt.
// Случай, когда самых длинных слов может быть несколько, не обрабатывать.

#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *f;
    char str[1001] = {0}, c, max_str[1001] = {0};
    unsigned int count = 0, max_len = 0;
    _Bool several_maxs = 0;

    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        do
        {
            c = fgetc(f);
            //printf("max_len = %d, max_str = %s, c = %c, str = %s\n", max_len, max_str, c, str);
            if ((c != '\n') && (c != ' ') && (c != EOF))
            {
                str[count++] = c;
            }
            else
            {
                //                if ((c == ' ') || (c == EOF) || )
                //                {
                if (max_len == count)
                {
                    several_maxs = 1;
                }
                if (max_len < count)
                {
                    max_len = count;
                    strcpy(max_str, str);
                    several_maxs = 0;
                }
                count = 0;
                str[0] = '\0';
                //                }
            }
        } while (c != EOF);
        //printf("out --> max_len = %d, max_str = %s, c = %c, str = %s\n", max_len, max_str, c, str);
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    if (several_maxs) // several max elements
        return 0;
    f = fopen("output.txt", "w");
    if (f != NULL)
    {
        for (size_t i = 0; i < max_len; i++)
        {
            fprintf(f, "%c", max_str[i]);
        }
    }
    else
    {
        printf("Can`t open file output.txt");
    }
    fclose(f);
    return 0;
}