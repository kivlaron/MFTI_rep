// Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет, похожи ли два английских слова по звучанию.
// На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код. Если коды двух слов совпадают, то слова, как правило, звучат похоже.

#include <stdio.h>
#include <string.h>

void readWord(char str[]);
void printToFile(char str[]);
_Bool isVowel(char c);
void convertToCode(char str[]);
char determineNumber(char c);
void lengthCorrection(char str[]);
void doubleDelete(char str[]);

int main(void)
{
    char str[20] = {0};
    readWord(str);
    convertToCode(str);
    printToFile(str);
    return 0;
}

void readWord(char str[])
{
    FILE *f;
    char c;
    unsigned int ind = 0;

    f = fopen("input.txt", "r");
    if (f != NULL)
    {
        while ((c = fgetc(f)) != EOF)
        {
            if ((c >= 'a') && (c <= 'z'))
            {
                if (ind == 0)
                    str[ind++] = c;
                else
                {
                    if (isVowel(c))
                    {
                        continue;
                    }
                    else
                    {
                        str[ind++] = c;
                    }
                }
            }
        }
    }
    else
    {
        printf("Can`t open file input.txt");
    }
    fclose(f);
    str[ind] = '\0';
    return;
}

void printToFile(char str[])
{
    FILE *f;
    unsigned int stars_count = 1;

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

_Bool isVowel(char c)
{
    char vowels[8] = {'a', 'e', 'h', 'i', 'o', 'u', 'w', 'y'};

    for (size_t i = 0; i < 8; i++)
    {
        if (c == vowels[i])
            return 1;
    }
    return 0;
}

char determineNumber(char c)
{
    switch (c)
    {
    case 'b':
    case 'f':
    case 'p':
    case 'v':
        return 1;
        break;
    case 'c':
    case 'g':
    case 'j':
    case 'k':
    case 'q':
    case 's':
    case 'x':
    case 'z':
        return 2;
        break;
    case 'd':
    case 't':
        return 3;
        break;
    case 'l':
        return 4;
        break;
    case 'm':
    case 'n':
        return 5;
        break;
    case 'r':
        return 6;
        break;
    default:
        break;
    }
}

void convertToCode(char str[])
{
    int count = strlen(str);
    for (size_t i = 1; i < count; i++)
    {
        str[i] = '0' + determineNumber(str[i]);
    }
    doubleDelete(str);
    lengthCorrection(str);
}

void doubleDelete(char str[])
{
    int count = strlen(str), ind_str = 1;
    char tmp[count];

    strcpy(tmp, str);
    for (size_t i = 1; i < count; i++)
    {
        if (tmp[i] != tmp[i - 1])
            str[ind_str++] = str[i];
    }
    str[ind_str] = '\0';
}

void lengthCorrection(char str[])
{
    int count = strlen(str);

    if (count < 4)
    {
        do
        {
            str[count++] = '0';
            str[count] = '\0';
        } while (count < 4);
    }
    else
    {
        str[4] = '\0';
    }
}