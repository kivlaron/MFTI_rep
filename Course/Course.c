#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "temp_functions.h"

const uint32_t COUNT_OF_ELEMENTS = 518400;

int main(int argc, char *argv[])
{
    struct sensor *info = malloc(sizeof(struct sensor) * COUNT_OF_ELEMENTS);
    statistics stats;
    char file_name[50];
    uint8_t month_num = 0;
    for (size_t i = 0; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
            case 'h':
                printf("-f entering the file name\n");
                printf("-m entering the month number\n");
                exit(0);
            case 'f':
                if (sscanf(argv[i + 1], "%s", file_name) == 0)
                {
                    printf("File name parameter is not recognised\n");
                }
                else
                {
                    printf("File name = %s\n", file_name);
                }
                break;
            case 'm':
                if (sscanf(argv[i + 1], "%hhd", &month_num) == 0)
                {
                    printf("Month number parameter is not recognised\n");
                }
                else
                {
                    if ((month_num > 12) || (month_num == 0))
                    {
                        printf("Month number must be less than 13 and more than 0\n");
                    }
                    else
                    {
                        printf("Month number = %d\n\n", month_num);
                    }
                }
                break;
            default:
                printf("Argument is not recognised\n");
                break;
            }
        }
    }
    readFromFile(file_name, info);
    stats_collect(info, month_num, COUNT_OF_ELEMENTS, &stats);
    if (month_num != 0)
    {
        printf("min temp in %d month = %d\n", month_num, stats.min_tmp_month);
        printf("max temp in %d month = %d\n", month_num, stats.max_tmp_month);
        printf("avr temp in %d month = %d\n", month_num, stats.avr_tmp_month);
        printf("\n");
    }
    printf("min temp in year = %d\n", stats.min_tmp_year);
    printf("max temp in year = %d\n", stats.max_tmp_year);
    printf("avr temp in year = %d\n", stats.avr_tmp_year);
    free(info);
    return 0;
}