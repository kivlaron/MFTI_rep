// В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы).
// Для решения задачи разработать функцию. Результат записать в output.txt.

#include <stdio.h>
#include <string.h>

void printToFile(char str[1001]);
void del_spaces(char str[1001]);
void readFromFile(char str[1001]);

int main(void)
{
    char str[1001] = {0};
    readFromFile(str);
    del_spaces(str);
    printToFile(str);
    return 0;
}

void printToFile(char str[1001])
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

void del_spaces(char str[1001])
{
    char tmp_c[1101];
    int ind = 0, start_ind = 0, count = strlen(str);
    _Bool flag_spaces = 0;
    while (str[start_ind] == ' ')
    {
        start_ind++;
    }
    for (size_t i = start_ind; i < count; i++)
    {
        if (str[i] == ' ')
        {
            if (!flag_spaces)
                tmp_c[ind++] = str[i];
            flag_spaces = 1;
        }
        if (str[i] != ' ')
        {
            tmp_c[ind++] = str[i];
            flag_spaces = 0;
        }
    }
    tmp_c[ind] = '\0';
    strcpy(str, tmp_c);
    return;
}

void readFromFile(char str[1001])
{
    FILE *f;
    f = fopen("input.txt", "r");
    unsigned int index = 0;
    char c;
    if (f != NULL)
    {
        fgets(str, 1000, f);
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
}