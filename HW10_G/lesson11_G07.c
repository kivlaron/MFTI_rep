// В файле input.txt считать символьную строку, не более 10 000 символов.
// Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке.
// Учитывать только английские буквы. Результат записать в файл output.txt.

#include <stdio.h>

int main(void)
{
    FILE *f;
    char str[1000], c;
    int lowercase = 0, uppercase = 0;

    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        while ((c = fgetc(f)) != EOF)
        {
            if (c != '\n')
            {
                if ((c >= 'a') && (c <= 'z'))
                    lowercase++;
                if ((c >= 'A') && (c <= 'Z'))
                    uppercase++;
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
        fprintf(f, "%d %d", lowercase, uppercase);
    }
    else
    {
        printf("Can`t open file output.txt");
    }
    return 0;
}