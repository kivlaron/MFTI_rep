// Cia очень любит равносторонние треугольники. Он все время выкладывает их из камней.
// Ling дал Cia камни и попросил его составить такой треугольник если это возможно.
// Помогите Cia сложить треугольник используя все камни или напечатайте слов NO, если это невозможно. Пример треугольников, которые составляет Cia:

#include <stdio.h>
#include <string.h>

void printToFile(unsigned int strings_count);
unsigned int readAndCountStars(void);
unsigned int countOfStrings(unsigned int);

int main(void)
{
    unsigned int count, strings_count;
    strings_count = countOfStrings(readAndCountStars());
    printToFile(strings_count);
    return 0;
}

unsigned int readAndCountStars(void)
{
    FILE *f;
    char c;
    unsigned int count = 0;
    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        while ((c = fgetc(f)) != EOF)
        {
            if (c == '*')
            {
                count++;
            }
        }
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    return count;
}

void printToFile(unsigned int strings_count)
{
    FILE *f;
    unsigned int stars_count = 1;
    f = fopen("output.txt", "w");
    if (f != NULL)
    {
        if (strings_count == 0)
            fprintf(f, "%s", "NO");
        else
        {
            while (strings_count > 0)
            {
                for (size_t i = 0; i < strings_count - 1; i++)
                {
                    fputc(' ', f);
                }
                for (size_t i = 0; i < stars_count; i++)
                {
                    fputc('*', f);
                    if (i < stars_count - 1)
                        fputc(' ', f);
                }
                if (strings_count > 1)
                    fputc('\n', f);
                strings_count--;
                stars_count ++;
            }
        }
    }
    else
    {
        printf("Can`t open file output.txt");
    }
    fclose(f);
    return;
}

unsigned int countOfStrings(unsigned int count)
{
    unsigned int summand = 2, tmp = 1;
    while (count >= tmp)
    {
        if (count == tmp)
            return summand - 1;
        tmp += summand;
        summand++;
    }
    return 0;
}