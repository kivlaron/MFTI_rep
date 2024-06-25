// В файле input.txt дана строка из 1000 символов. Показать номера символов, совпадающих с последним символом строки.
// Результат записать в файл output.txt

#include <stdio.h>

int main(void) {
    int count = 0;
    FILE *f;
    char s[1000];
    f = fopen("input.txt", "r");
    if (f != NULL) {
        while (((s[count++] = fgetc(f)) != EOF) && (s[count] != '\n'));
    } else {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    s[count] = '\0';
    count -= 2;
    f = fopen("output.txt", "w");
    for (int i = 0; i < count; i++)
    {
        if (s[i] == s[count])
            fprintf(f, "%d ", i);
    }
    fclose(f);
    return 0;
}