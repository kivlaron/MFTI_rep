// Разработать функцию дана строка из маленьких английских букв. Составить из символов палиндром максимальной длинны.
// При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке. Записать ответ в файл output.txt.

#include <stdio.h>
#include <string.h>

void printToFile(char str[]);
void find_couples(char str[], char couples[]);
void sort_string(char str[]);
void prepare_res(char str[], char couples[]);
void readFromFile(char str[]);

int main(void)
{
    char str[1001] = {0}, couples[500] = {0};
    readFromFile(str);
    find_couples(str, couples);
    sort_string(str);
    sort_string(couples);
    prepare_res(str, couples);
    printToFile(str);
    return 0;
}

void printToFile(char str[])
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

void readFromFile(char str[])
{
    FILE *f;
    f = fopen("input.txt", "r");
    size_t count;
    if (f != NULL)
    {
        count = fread(str, sizeof(char), 1000, f);
        str[count - 1] = '\0';           // в автотестах считывается лишний неведомый символ
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
}

void find_couples(char str[], char couples[])
{
    int count = strlen(str), couples_count = 0;
    char zero_symbol = 0x7F;
    for (size_t i = 0; i < count; i++)
    {
        if (str[i] == zero_symbol)
            continue;
        for (size_t j = 0; j < count; j++)
        {
            if (i != j)
            {
                if (str[i] == str[j])
                {
                    couples[couples_count++] = str[i];
                    str[i] = zero_symbol;
                    str[j] = zero_symbol;
                    break;
                }
            }
        }
    }
}

void sort_string(char str[])
{
    int count = strlen(str);
    char c_tmp;
    for (size_t i = 0; i < count; i++)
    {
        for (size_t j = i + 1; j < count; j++)
        {
            if (str[j] < str[i]) {
                c_tmp = str[j];
                str[j] = str[i];
                str[i] = c_tmp;
            }
        }
    }
}

void prepare_res(char str[], char couples[])
{
    char tmp = str[0];
    int count = strlen(couples), count_res = 0;
    for (size_t i = 0; i < count; i++)
    {
        str[count_res++] = couples[i];
    }
    if (tmp != 0x7F)                   //if the middle symbol exist
        str[count_res++] = tmp;
    for (int i = count - 1; i >= 0; i--)
    {
        str[count_res++] = couples[i];
    }
    str[count_res] = '\0';
}