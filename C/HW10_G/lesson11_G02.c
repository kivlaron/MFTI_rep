// Считать число N из файла input.txt. Сформировать строку из N символов. N четное число, не превосходящее 26.
// На четных позициях должны находится четные цифры в порядке возрастания, кроме 0, на нечетных позициях - заглавные буквы в порядке следования
// в английском алфавите. Результат записать в файл output.txt

#include <stdio.h>

int main(void) {
    int n;
    FILE *f;
    f = fopen("input.txt", "r");
    if (f != NULL) {
        fscanf (f, "%d", &n);
    } else {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    if (n > 26)
        n = 26;
    if (n%2 != 0)
        n ++;
    char c[n];
    f = fopen("output.txt", "w");
    for (size_t i = 1; i <= n; i++)
    {
        if (i%2 == 0)
            c[i - 1] = '0' + (i%8 != 0 ? i%8 : 8);
        else
            if (i > 1) {
                c[i - 1] = c[i - 3] + 1;
            }
            else
                c[i - 1] = 'A';
    }
    for (size_t i = 0; i < n; i++)
    {
        fprintf(f, "%c", c[i]);
    }
    fclose(f);
    return 0;
}