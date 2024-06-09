// Написать только одну функцию, которая ставит в начало массива все
// четные элементы, а в конец – все нечетные. Не нарушайте порядок
// следования чисел между собой. Строго согласно прототипу:.
// void sort_even_odd(int n, int a[])

//#include <stdio.h>

void sort_even_odd(int n, int a[]) {
    int temp, j = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i]%2 == 0) {
            if (i != j) {
                temp = a[i];
                for (int k = i; k > j; k --) {
                    a[k] = a[k - 1];
                }
                a[j] = temp;
            }
            j ++;
        }
    }
}

/*int main(void)
{
    //int a[] = {20, 19, 18, 17, 16, 22, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int a[] = {1, 0, 1, 0, 1};
    sort_even_odd(sizeof(a)/sizeof(a[0]), a);
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        printf("%d ", a[i]);
    }
}*/
