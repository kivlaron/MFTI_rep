// Написать функцию и программу демонстрирующую работу данной функции.
// Вывести в порядке возрастания цифры, входящие в десятичную запись
// натурального числа N, не более 1000 цифр. Цифра пробел сколько раз
// данная цифра встречается в числе.

#include <stdio.h>
#include <string.h>

void filling(char input_num[], int quant[]);
void print(int quant[]);

int main(int argc, char **argv)
{
    char input_num[1000];
    int quant[10] = {0};
    scanf("%s", input_num);
    filling(input_num, quant);
    print(quant);
}

void filling(char input_num[], int quant[]) {
    for (int i = 0; i < strlen(input_num); i ++) {
        quant[input_num[i] - 48]++;
    }
}

void print(int quant[]) {
    for (int i = 0; i < 10; i ++) {
        if (quant[i] != 0)
            printf("%d %d\n", i, quant[i]);
    }
}
