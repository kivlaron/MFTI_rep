// В файле input.txt записан полный адрес файла (возможно, без расширения).
// Необходимо изменить его расширение на ".html" и записать результат в файл output.txt.

#include <stdio.h>
#include <string.h>
void printToFile(char str[], unsigned int count);

int main(void)
{
    FILE *f;
    char str[1000] = {0}, c;
    unsigned int count = 0, from = 0, i;

    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        while ((c = fgetc(f)) != EOF)
        {
            if (c != '\n')
            {
                str[count++] = c;
                if (c == '/') {
                    from = count;
                }
            }
        }
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    for (i = from; i < count; i++)
    {
        if (str[i] == '.') {
            from = i;
            break;
        }
    }
    if (i == count)
        from = i;
    str[from] = '\0';
    strcat(str, ".html");
    printToFile(str, strlen(str));
    return 0;
}

void printToFile(char str[], unsigned int count)
{
    FILE *f;
    f = fopen("output.txt", "w");
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