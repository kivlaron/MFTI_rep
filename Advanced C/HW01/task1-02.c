#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    const uint8_t A_COUNT = 26;
    char c;
    uint16_t shift;

    scanf("%"SCNd16, &shift);
    do
    {
        c = getchar();
        if ((c >= 'a') && (c <= 'z'))
        {
            printf("%c", (c - 'a' + shift)%A_COUNT + 'a');
        } else if ((c >= 'A') && (c <= 'Z')) {
            printf("%c", (c - 'A' + shift)%A_COUNT + 'A');
        } else if (c == ' ') {
            printf(" ");
        }
    } while (c != '.');
    return 0;
}