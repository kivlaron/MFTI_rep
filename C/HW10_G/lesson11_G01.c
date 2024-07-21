// В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.

#include <stdio.h>

int main(void) {
    char fstr[100] = {0}, c;
    FILE *f;
    int count = 0;
    f = fopen("input.txt", "r");
    if (f != NULL) {
        while ((c = fgetc(f)) != EOF) {
            if (c != '\n')
                fstr[count++] = c;
        }
        //fscanf (f, "%[^EOF]s", fstr);
    } else {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    f = fopen("output.txt", "w");
    fprintf(f, "%s", fstr);
    for (size_t i = 0; i < 2; i++)
    {
        fprintf(f, ", %s", fstr);
    }
    fprintf(f, " %d", count);
    fclose(f);
    return 0;
}