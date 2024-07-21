// В файле input.txt дано предложение. Необходимо заменить все имена «Ling» на «Cao» и результат записать в файл output.txt.

#include <stdio.h>
#include <string.h>

void printToFile(char str[1001]);
void change(char str[1001]);
void writeToTmp(char tmp[5], char c);

int main(void)
{
    char str[1001] = {0};
    change(str);
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

void change(char str[1001])
{
    FILE *f;
    char c, tmp[5] = {0};
    int ind_tmp = 0, count = 0;
    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        while ((c = fgetc(f)) != EOF)
        {
            if (c != '\n')
            {
                str[count++] = c;
                writeToTmp(tmp, c);
                if (!strcmp(tmp, "Ling")) {
                    str[count - 4] = '\0';
                    strcat(str, "Cao");
                    count = strlen(str);
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

void writeToTmp(char tmp[5], char c) {
    int len = strlen(tmp);
    if (len > 3) {
        for (size_t i = 0; i < 4; i++)
        {
            tmp[i] = i + 1 <= 3 ? tmp [i + 1] : c;
        }
    } else {
        tmp[len] = c;
    }
}