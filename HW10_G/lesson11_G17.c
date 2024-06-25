// В файле input.txt записаны символы.
// Необходимо разработать функцию, которая меняет местами пары соседних символов не обращая внимание на символы пробел.
// Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. Результат записать в файл output.txt.

#include <stdio.h>
#include <string.h>

void printToFile(char str[1000]);
void change(char str[1000]);
void readFromFile(char str[1000]);

int main(void)
{
    char str[1000] = {0};
    readFromFile(str);
    change(str);
    printToFile(str);
    return 0;
}

void printToFile(char str[1000])
{
    FILE *f;
    f = fopen("output.txt", "w");
    if (f != NULL)
    {
        fprintf(f, "%s", str);
    }
    else
    {
        printf("Can`t open file output.txt");
    }
    fclose(f);
    return;
}

void change(char str[1000])
{
    char tmp_c;
    int i_prev = -1, count = strlen(str);
    for (size_t i = 0; i < count; i++)
    {
        if (str[i] != ' ')
        {
            if (i_prev == -1)
            {
                i_prev = i;
            }
            else
            {
                tmp_c = str[i];
                str[i] = str[i_prev];
                str[i_prev] = tmp_c;
                i_prev = -1;
            }
        }
    }
}

void readFromFile(char str[1000])
{
    FILE *f;
    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        fscanf(f, "%[^\n]", str);
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
}