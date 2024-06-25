// В файле input.txt дана символьная строка не более 1000 символов.
// Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.

#include <stdio.h>

int main(void)
{
    FILE *fr, *fw;
    char c;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    if ((fr != NULL) && (fw != NULL))
    {
        while ((c = fgetc(fr)) != EOF)
        {
            if ((c == 'a') || (c == 'A'))
            {
                c = c == 'a' ? 'b' : c;
                c = c == 'A' ? 'B' : c;
            }
            else
            {
                if ((c == 'b') || (c == 'B'))
                {
                    c = c == 'b' ? 'a' : c;
                    c = c == 'B' ? 'A' : c;
                }
            }
            fprintf(fw, "%c", c);
        }
    }
    else
    {
        if (fr == NULL)
            printf("Can`t open file input.txt");
        if (fw == NULL)
            printf("Can`t open file output.txt");
    }
    fclose(fr);
    fclose(fw);
    return 0;
}