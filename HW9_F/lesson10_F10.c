// Дана строка состоящая из маленьких латинских букв 'a'..'z'. В конце строки точка.
// Необходимо заменить повторяющиеся буквы на <буква><количество повторений>

#include <stdio.h>

int count(int start_pos, char s[]);

int main(int argc, char **argv)
{
    char s[1000];
    int i = 0;
    while ((s[i++] = getchar()) != '.');
    int tmp = 0;
    do {
        tmp = count(tmp, s) + tmp;
    } while (s[tmp] != '.');
    return 0;
}

int count(int start_pos, char s[]) {
    int res = 1;
    char tmp = s[start_pos];
    printf("%c", tmp);
    do {
        if (tmp == s[++start_pos])
            res ++;
        else
            break;
    } while (s[start_pos] != '.');
    printf("%d", res);
    return res;
}
