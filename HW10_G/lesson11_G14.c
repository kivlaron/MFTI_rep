// В файле input.txt в одной строке фамилию, имя и отчество. Сформировать файл приветствие output.txt, где останутся имя и фамилия

#include <stdio.h>

void printToFile(char name[3][100]);
void readNames(char name[3][100]);

int main(void)
{
    char name[3][100] = {0};
    readNames(name);
    printToFile(name);
    return 0;
}

void printToFile(char name[3][100])
{
    FILE *f;
    f = fopen("output.txt", "w");
    if (f != NULL)
    {
        fputs("Hello, ", f);
        fprintf(f, "%s %s!", name[1], name[0]);
    }
    else
    {
        printf("Can`t open file output.txt");
    }
    fclose(f);
}

void readNames(char name[3][100])
{
    FILE *f;
    char c;
    unsigned int i = 0, count = 0;
    _Bool several_spaces = 0;
    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        while ((c = fgetc(f)) != EOF)
        {
            if (c != '\n')
            {
                if (c != ' ')
                {
                    name[i][count++] = c;
                    several_spaces = 0;
                }
                else if (!several_spaces)
                {
                    i++;
                    count = 0;
                    several_spaces = 1;
                }
            }
        }
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
}