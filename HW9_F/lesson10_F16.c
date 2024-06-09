// Известно, что шахматная доска имеет размерность 8х8 и состоит из клеток 2х цветов, например, черного и белого (см. рисунок).
// Каждая клетка имеет координату, состоящую из буквы и цифры. Горизонтальное расположение клетки определяется буквой от A до H,
// а вертикальное – цифрой от 1 до 8. Заметим, что клетка с координатой А1 имеет черный цвет. Требуется по заданной координате определить цвет клетки.

#include <stdio.h>

int calculate(int num1, int num2);

int main(int argc, char **argv)
{
    int num1, num2;
    char data[2];
    scanf("%s", data);
    num1 = data[0] - 'A' + 1;
    num2 = data[1] - '0';
    calculate(num1, num2) != 0 ? printf("WHITE") : printf("BLACK");
}

int calculate(int num1, int num2) {
    return num1%2 - num2%2;
}
