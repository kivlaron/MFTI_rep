#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint16_t count = 0, a, max = 0, cnt_max = 1;

    scanf("%" SCNd16, &count);
    for (size_t i = 0; i < count; i++)
    {
        scanf("%" SCNd16, &a);
        if (max < a)
        {
            max = a;
            cnt_max = 1;
        }
        else
        {
            if (max == a)
            {
                cnt_max++;
            }
        }
    }
    printf("%" PRId16, cnt_max);
    return 0;
}