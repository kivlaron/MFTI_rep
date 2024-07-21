// В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом.
// Найдите только те символы слов, которые встречаются в обоих словах только один раз.
// Напечатайте их через пробел в файл output.txt в лексикографическом порядке.

#include <stdio.h>
#include <string.h>

int includeCount(char s, char str[], int size_str);

int main(void) {
    int len_s1, len_s2;
    FILE *f;
    char s1[200], s2[100], flag = 0;
    // ---------- read ------------
    f = fopen("input.txt", "r");
    if (f != NULL) {
        fscanf(f, "%s %[^EOF]s", s1, s2);
    } else {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    // ---------- write ------------
    len_s1 = strlen(s1);
    len_s2 = strlen(s2);
    f = fopen("output.txt", "w");
    for (size_t i = 0; i < len_s1; i++)
    {
        if (includeCount(s1[i], s1, len_s1) == 1)
            if (includeCount(s1[i], s2, len_s2) == 1)
                fprintf(f, "%c ", s1[i]);
    }
    fclose (f);
    return 0;
}

int includeCount(char s, char str[], int size_str) {
    int count = 0;
    for (size_t i = 0; i < size_str; i++)
    {
        if (s == str[i])
            count ++;        
    }
    return count;
}