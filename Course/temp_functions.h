#include <stdint.h>
#include <stdbool.h>

struct sensor
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};

typedef struct {
    int8_t avr_tmp_month;
    int8_t min_tmp_month;
    int8_t max_tmp_month;
    int8_t avr_tmp_year;
    int8_t min_tmp_year;
    int8_t max_tmp_year;
} statistics;

void readFromFile(char file_name[], struct sensor info[]);
void addYear(struct sensor info[], uint32_t number, uint16_t year);
void addMonth(struct sensor info[], uint32_t number, uint8_t month);
void addDay(struct sensor info[], uint32_t number, uint8_t day);
void addHour(struct sensor info[], uint32_t number, uint8_t hours);
void addMinute(struct sensor info[], uint32_t number, uint8_t minutes);
void addTemperature(struct sensor info[], uint32_t number, int8_t temperature);

int8_t avrTempMonth(struct sensor info[], uint8_t month_number, uint32_t count);
int8_t minTempMonth(struct sensor info[], uint8_t month_number, uint32_t count);
int8_t maxTempMonth(struct sensor info[], uint8_t month_number, uint32_t count);
int8_t avrTempYear(struct sensor info[], uint32_t count);
int8_t minTempYear(struct sensor info[], uint32_t count);
int8_t maxTempYear(struct sensor info[], uint32_t count);
void stats_collect(struct sensor info[], uint8_t month_number, uint32_t count, statistics *stats);

_Bool errors(uint8_t err_code, char str[], uint32_t str_num);
uint8_t separateYear(uint16_t *year, char str[]);
uint8_t separateMonth(uint8_t *month, char str[]);
uint8_t separateDay(uint8_t *day, char str[]);
uint8_t separateHour(uint8_t *hour, char str[]);
uint8_t separateMinute(uint8_t *minute, char str[]);
uint8_t separateTemperature(int8_t *temperature, char str[]);