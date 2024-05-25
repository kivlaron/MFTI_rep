// Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум
// массивам: в одни помещать только положительные, во второй - только
// отрицательные. Числа, равные нулю, игнорировать. Вывести на экран
// все элементы обоих массивов.
#include <stdio.h>

const unsigned int SZ = 10;

void inputArr(int posArr[], int negArr[], int* count_pos, int* count_neg);
void outputArr(int arr[], int count);

int main(void)
{
    int posArr[SZ], negArr[SZ], count_pos = 0, count_neg = 0;
    inputArr(posArr, negArr, &count_pos, &count_neg);
    outputArr(posArr, count_pos);
    outputArr(negArr, count_neg);
    return 0;
}

void inputArr(int posArr[], int negArr[], int* count_pos, int* count_neg) {
    int temp;
    for (int i = 0; i < SZ; i ++) {
        scanf("%d", &temp);
        if (temp > 0)
            posArr[(*count_pos) ++] = temp;
        if (temp < 0)
            negArr[(*count_neg) ++] = temp;
    }
}

void outputArr(int arr[], int length_arr) {
    for (int i = 0; i < length_arr; i ++)
        printf("%d ", arr[i]);
}
