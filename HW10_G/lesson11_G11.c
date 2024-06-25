// В файле input.txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. Ответ записать в файл output.txt.

#include <stdio.h>

int main(void)
{
    FILE *f;
    char str[1000] = {0}, c;
    unsigned int count = 0, a_words = 0;
    _Bool first_time = 1;

    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        do
        {
            c = fgetc(f);
            if ((c != '\n') && (c != ' ') && (c != EOF))
            {
                str[count++] = c;
                str[count] = '\0';
                first_time = 1;
            }
            else
            {
                if ((str[count - 1] == 'a') && (first_time))
                {
                    a_words++;
                    first_time = 0;
                }
            }
        } while (c != EOF);
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    f = fopen("output.txt", "w");
    if (f != NULL)
    {
        fprintf(f, "%d", a_words);
    }
    else
    {
        printf("Can`t open file output.txt");
    }
    fclose(f);
    return 0;
}