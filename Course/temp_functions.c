#include <stdio.h>
#include <stdint.h>
#include <string.h>

struct sensor
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};

typedef struct
{
    int8_t avr_tmp_month;
    int8_t min_tmp_month;
    int8_t max_tmp_month;
    int8_t avr_tmp_year;
    int8_t min_tmp_year;
    int8_t max_tmp_year;
} statistics;

_Bool errors(uint8_t err_code, char str[], uint32_t str_num)
{
    switch (err_code)
    {
    case 0:
        return 0;
    case 1:
        printf("Code error = %d, Incorrect year format\n", err_code);
        printf("In string number %d: %s\n\n", str_num, str);
        break;
    case 2:
        printf("Code error = %d, Incorrect month format\n", err_code);
        printf("In string number %d: %s\n\n", str_num, str);
        break;
    case 3:
        printf("Code error = %d, Incorrect day format\n", err_code);
        printf("In string number %d: %s\n\n", str_num, str);
        break;
    case 6:
        printf("Code error = %d, Incorrect temperature format\n", err_code);
        printf("In string number %d: %s\n\n", str_num, str);
        break;
    case 10:
        printf("Code error = %d, Error working with file\n", err_code);
        printf("In string number %d: %s\n\n", str_num, str);
        break;
    default:
        printf("Code error = %d, Unidentified error\n", err_code);
        printf("In string number %d: %s\n\n", str_num, str);
        break;
    }
    return 1;
}

uint8_t separateYear(uint16_t *year, char str[])
{
    uint8_t count = strlen(str), num_count = 0;
    uint16_t res = 0;

    for (size_t i = 0; i < count; i++)
    {
        if (str[i] == ';')
        {
            if (num_count != 4)
                return 1; // code of error "Incorrect year format"
            else
            {
                *year = res;
                return 0;
            }
        }
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            res = str[i] - '0' + res * 10;
            num_count++;
        }
        else
        {
            if (str[i] != ' ')
            {
                return 1; // code of error "Incorrect year format"
            }
        }
    }
}

uint8_t separateMonth(uint8_t *month, char str[])
{
    uint8_t count = strlen(str), num_count = 0, start_ind = 0;
    uint16_t res = 0;

    while (num_count < 1)
    {
        if (str[start_ind++] == ';')
            num_count++;
    }
    num_count = 0;
    for (size_t i = start_ind; i < count; i++)
    {
        if (str[i] == ';')
        {
            if ((num_count < 1) || (num_count > 2))
                return 2; // code of error "Incorrect month format"
            else
            {
                *month = res;
                return 0;
            }
        }
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            res = str[i] - '0' + res * 10;
            num_count++;
        }
        else
        {
            if (str[i] != ' ')
            {
                return 2; // code of error "Incorrect month format"
            }
        }
    }
}

uint8_t separateDay(uint8_t *day, char str[])
{
    uint8_t count = strlen(str), num_count = 0, start_ind = 0;
    uint16_t res = 0;

    while (num_count < 2)
    {
        if (str[start_ind++] == ';')
            num_count++;
    }
    num_count = 0;
    for (size_t i = start_ind; i < count; i++)
    {
        if (str[i] == ';')
        {
            if ((num_count < 1) || (num_count > 2))
                return 3; // code of error "Incorrect day format"
            else
            {
                *day = res;
                return 0;
            }
        }
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            res = str[i] - '0' + res * 10;
            num_count++;
        }
        else
        {
            if (str[i] != ' ')
            {
                return 3; // code of error "Incorrect day format"
            }
        }
    }
}

uint8_t separateHour(uint8_t *hour, char str[])
{
    uint8_t count = strlen(str), num_count = 0, start_ind = 0;
    uint16_t res = 0;

    while (num_count < 3)
    {
        if (str[start_ind++] == ';')
            num_count++;
    }
    num_count = 0;
    for (size_t i = start_ind; i < count; i++)
    {
        if (str[i] == ';')
        {
            if ((num_count < 1) || (num_count > 2))
                return 4; // code of error "Incorrect hour format"
            else
            {
                *hour = res;
                return 0;
            }
        }
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            res = str[i] - '0' + res * 10;
            num_count++;
        }
        else
        {
            if (str[i] != ' ')
            {
                return 4; // code of error "Incorrect hour format"
            }
        }
    }
}

uint8_t separateMinute(uint8_t *minute, char str[])
{
    uint8_t count = strlen(str), num_count = 0, start_ind = 0;
    uint16_t res = 0;

    while (num_count < 4)
    {
        if (str[start_ind++] == ';')
            num_count++;
    }
    num_count = 0;
    for (size_t i = start_ind; i < count; i++)
    {
        if (str[i] == ';')
        {
            if ((num_count < 1) || (num_count > 2))
                return 5; // code of error "Incorrect minute format"
            else
            {
                *minute = res;
                return 0;
            }
        }
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            res = str[i] - '0' + res * 10;
            num_count++;
        }
        else
        {
            if (str[i] != ' ')
            {
                return 5; // code of error "Incorrect minute format"
            }
        }
    }
}

uint8_t separateTemperature(int8_t *temperature, char str[])
{
    uint8_t count = strlen(str), num_count = 0, start_ind = 0;
    uint16_t res = 0;
    _Bool minus_flag = 0;

    while (num_count < 5)
    {
        if (str[start_ind++] == ';')
            num_count++;
    }
    num_count = 0;
    for (size_t i = start_ind; i <= count; i++)
    {
        if (str[i] == '\0')
        {
            if ((num_count < 1) || (num_count > 2))
                return 6; // code of error "Incorrect temperature format"
            else
            {
                *temperature = res * (minus_flag ? -1 : 1);
                return 0;
            }
        }
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            res = str[i] - '0' + res * 10;
            num_count++;
        }
        else if (str[i] == '-')
        {
            minus_flag = 1;
        }
        else
        {
            if (str[i] != ' ')
            {
                return 6; // code of error "Incorrect temperature format"
            }
        }
    }
}

void addYear(struct sensor info[], uint32_t number, uint16_t year)
{
    info[number].year = year;
}

void addMonth(struct sensor info[], uint32_t number, uint8_t month)
{
    info[number].month = month;
}

void addDay(struct sensor info[], uint32_t number, uint8_t day)
{
    info[number].day = day;
}

void addHour(struct sensor info[], uint32_t number, uint8_t hour)
{
    info[number].hour = hour;
}

void addMinute(struct sensor info[], uint32_t number, uint8_t minute)
{
    info[number].minute = minute;
}

void addTemperature(struct sensor info[], uint32_t number, int8_t temperature)
{
    info[number].temperature = temperature;
}

uint32_t readFromFile(char file_name[], struct sensor info[]) // Add datas from file to massive of struct
{
    FILE *f;
    char str[30] = {0};
    char c;
    uint16_t year;
    uint8_t count = 0, month = 0, day = 0, hour = 0, minute = 0;
    int8_t temperature = 0;
    uint32_t str_num = 1;
    _Bool err_is_exist = 0;

    f = fopen(file_name, "r");
    if (f != NULL)
    {
        do
        {
            while (!feof(f))
            {
                c = fgetc(f);
                if ((c != '\n') && (!feof(f)))
                {
                    str[count++] = c;
                }
                else
                    break;
            }
            str[count] = '\0';
            count = 0;
            err_is_exist = errors(separateYear(&year, str), str, str_num);
            err_is_exist = errors(separateMonth(&month, str), str, str_num);
            err_is_exist = errors(separateDay(&day, str), str, str_num);
            err_is_exist = errors(separateHour(&hour, str), str, str_num);
            err_is_exist = errors(separateMinute(&minute, str), str, str_num);
            err_is_exist = errors(separateTemperature(&temperature, str), str, str_num);
            if (!err_is_exist)
            {
                addYear(info, str_num - 1, year);
                addMonth(info, str_num - 1, month);
                addDay(info, str_num - 1, day);
                addHour(info, str_num - 1, hour);
                addMinute(info, str_num - 1, minute);
                addTemperature(info, str_num - 1, temperature);
                str_num++;
            }
        } while (!feof(f));
    }
    else
    {
        printf("Can`t open the file %s\n", file_name);
    }
    fclose(f);
    return str_num - 1;
}

void stats_collect(struct sensor info[], uint8_t month_number, uint32_t count, statistics *stats)
{
    int32_t avr_t_m = 0, avr_t_y = 0;
    int8_t min_t_m = 127, min_t_y = 127;
    int8_t max_t_m = -128, max_t_y = -128;
    int32_t measure_m_num = 0, measure_y_num = 0;

    for (size_t i = 0; i < count; i++)
    {
        if (month_number != 0)
        {
            if (info[i].month == month_number)
            {
                avr_t_m += info[i].temperature;                                          // calculate month avr temperature
                measure_m_num++;                                                         // calculate month avr temperature
                min_t_m = min_t_m > info[i].temperature ? info[i].temperature : min_t_m; // calculate month min temperature
                max_t_m = max_t_m < info[i].temperature ? info[i].temperature : max_t_m; // calculate month max temperature
            }
        }
        avr_t_y += info[i].temperature;                                          // calculate year avr temperature
        measure_y_num++;                                                         // calculate year avr temperature
        min_t_y = min_t_y > info[i].temperature ? info[i].temperature : min_t_y; // calculate year min temperature
        max_t_y = max_t_y < info[i].temperature ? info[i].temperature : max_t_y; // calculate year max temperature
    }
    if (month_number != 0)
    {
        stats->avr_tmp_month = avr_t_m / measure_m_num;
        stats->min_tmp_month = min_t_m;
        stats->max_tmp_month = max_t_m;
    }
    stats->avr_tmp_year = avr_t_y / measure_y_num;
    stats->max_tmp_year = max_t_y;
    stats->min_tmp_year = min_t_y;
}