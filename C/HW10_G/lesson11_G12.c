// В файле input.txt дано предложение требуется разобрать его на отдельные слова. Напечатать каждое слово на отдельной строке в файл output.txt.

#include <stdio.h>
void printToFile(char str[], unsigned int count);

int main(void)
{
    FILE *f;
    char str[1000] = {0}, c;
    unsigned int count = 0, a_words = 0;

    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        while ((c = fgetc(f)) != EOF)
        {
            if ((c != '\n') && (c != ' '))
            {
                str[count++] = c;
            }
            else
            {
                if (count != 0)
                {
                    printToFile(str, count);
                    str[0] = '\0';
                    count = 0;
                }
            }
        }
        if (c == EOF)
            printToFile(str, count);
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    return 0;
}

void printToFile(char str[], unsigned int count)
{
    FILE *f;
    f = fopen("output.txt", "a");
    if (f != NULL)
    {
        for (size_t i = 0; i < count; i++)
        {
            fprintf(f, "%c", str[i]);
        }
        fprintf(f, "\n");
    }
    else
    {
        printf("Can`t open file output.txt");
    }
    fclose(f);
}