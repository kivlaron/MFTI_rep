#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses/ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

// #define MIN_Y  2
#define CONTROLS 3
enum
{
    LEFT = 1,
    UP,
    RIGHT,
    DOWN,
    STOP_GAME = KEY_F(10)
};

enum
{
    MAX_TAIL_SIZE = 100,
    START_TAIL_SIZE = 3,
    MAX_FOOD_SIZE = 25,
    FOOD_EXPIRE_SECONDS = 25
};

// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
} control_buttons;

struct control_buttons default_controls[CONTROLS] = {{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT},
                                                     {'S', 'W', 'A', 'D'},
                                                     {'s', 'w', 'a', 'd'}};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls[CONTROLS];
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

struct food
{
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t = {0, 0};
    for (size_t i = 0; i < size; i++)
    {
        t[i] = init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

void initSnake(snake_t *head, size_t size, int x, int y)
{
    tail_t *tail = (tail_t *)malloc(MAX_TAIL_SIZE * sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size + 1;
    for (size_t i = 0; i < CONTROLS; i++)
    {
        head->controls[i] = default_controls[i];
    }
}

void initFood(struct food f[])
{
    struct food init = {0, 0, 0, 0};
    for (size_t i = 0; i < MAX_FOOD_SIZE; i++)
    {
        f[i] = init;
    }
}

/*
 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head)
{
    char ch = '@';
    int max_x = 0;
    int max_y = 0;
    getmaxyx(stdscr, max_y, max_x);  // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
    case LEFT:
        if (head->x <= 0) // Циклическое движение, чтобы не уходить за пределы экрана
            head->x = max_x;
        mvprintw(head->y, --(head->x), "%c", ch);
        break;
    case RIGHT:
        if (head->x >= max_x)
            head->x = 0;
        mvprintw(head->y, ++(head->x), "%c", ch);
        break;
    case UP:
        if (head->y <= 0)
            head->y = max_y;
        mvprintw(--(head->y), head->x, "%c", ch);
        break;
    case DOWN:
        if (head->y >= max_y) // Циклическое движение, чтобы не уходить за пределы экрана
            head->y = 0;
        mvprintw(++(head->y), head->x, "%c", ch);
        break;
    default:
        break;
    }
}

int checkDirection(struct snake_t *snake, const int32_t key)
{
    for (size_t i = 0; i < CONTROLS; i++)
    {
        if ((key == snake->controls[i].down) && (snake->direction == UP))
        {
            return 0;
        }
        else if ((key == snake->controls[i].up) && (snake->direction == DOWN))
        {
            return 0;
        }
        else if ((key == snake->controls[i].right) && (snake->direction == LEFT))
        {
            return 0;
        }
        else if ((key == snake->controls[i].left) && (snake->direction == RIGHT))
        {
            return 0;
        }
    }
    return 1;
}
void changeDirection(struct snake_t *snake, const int32_t key)
{
    if (checkDirection(snake, key))
    {
        for (size_t i = 0; i < CONTROLS; i++)
        {
            if (key == snake->controls[i].down)
            {
                // if (snake->direction != UP)
                snake->direction = DOWN;
            }
            else if (key == snake->controls[i].up)
            {
                // if (snake->direction != DOWN)
                snake->direction = UP;
            }
            else if (key == snake->controls[i].right)
            {
                // if (snake->direction != LEFT)
                snake->direction = RIGHT;
            }
            else if (key == snake->controls[i].left)
            {
                // if (snake->direction != RIGHT)
                snake->direction = LEFT;
            }
        }
    }
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize - 1].y, head->tail[head->tsize - 1].x, " ");
    for (size_t i = head->tsize - 1; i > 0; i--)
    {
        head->tail[i] = head->tail[i - 1];
        // if (head->tail[i].y || head->tail[i].x)
        mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

_Bool isCrush(snake_t *snake)
{
    int max_x = 0;
    int max_y = 0;
    int x = snake->x;
    int y = snake->y;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    // mvprintw(5, 5, "max_x/2 = %d, max_y/2 = %d\n", max_x/2, max_y/2);
    for (int i = 0; i < snake->tsize; i++)
    {
        // timeout(1000);// - не работает
        if (x == snake->tail[i].x)
        {
            if (y == snake->tail[i].y)
            {
                mvprintw(max_y / 2, max_x / 2 - 7, " B U S T E D ");
                refresh();
                timeout(500); // - не работает
                sleep(1);
                mvprintw(max_y / 2, max_x / 2 - 7, "             ");
                refresh();
                timeout(500); // - не работает
                sleep(1);
                mvprintw(max_y / 2, max_x / 2 - 7, " B U S T E D ");
                refresh();
                timeout(1500); // - не работает
                sleep(2);
                return 1;
            }
        }
    }
    return 0;
}

void putFoodSeed(struct food *fp)
{
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % max_x;
    fp->y = rand() % (max_y - 1) + 1;
    fp->put_time = time(NULL) - rand() % 20;
    fp->point = '$';
    fp->enable = 1;
    mvprintw(fp->y, fp->x, "%c", fp->point);
};

void putFood(struct food f[])
{
    for (size_t i = 0; i < MAX_FOOD_SIZE; i++)
    {
        putFoodSeed(&f[i]);
    }
};

void refreshFood(struct food f[], struct snake_t *head)
{
    int max_x;
    int max_y;
    getmaxyx(stdscr, max_y, max_x);
    for (size_t i = 0; i < MAX_FOOD_SIZE; i++)
    {
        // mvprintw(i, 1, "time = %lld, f[%lld].put_time = %lld, time - put_time = %lld", time(NULL), i, f[i].put_time, time(NULL) - f[i].put_time);
        if (time(NULL) - f[i].put_time > FOOD_EXPIRE_SECONDS)
        {
            // mvprintw(i, 1, "food [%lld] enable = %d", i, f[i].enable);
            // if (f[i].enable) {
            putFoodSeed(&f[i]);
            //}
        }
        if ((head->x == f[i].x) && (head->y == f[i].y))
        {
            putFoodSeed(&f[i]);
            head->tsize++;
            if (head->tsize == MAX_TAIL_SIZE)
            {
                mvprintw(max_y / 2, max_x / 2 - 10, " Y O U   W I N !!! ");
                refresh();
                timeout(500); // - не работает
                sleep(1); // - работает всегда, но в секундах
                mvprintw(max_y / 2, max_x / 2 - 10, "                   ");
                refresh();
                timeout(500); // - не работает
                sleep(1); // - работает всегда, но в секундах
                mvprintw(max_y / 2, max_x / 2 - 10, " Y O U   W I N !!! ");
                refresh();
                timeout(1500); // - не работает
                sleep(2); // - работает всегда, но в секундах
                exit(1);
            }
        }
        mvprintw(f[i].y, f[i].x, "%c", f[i].point);
    }
}

int main()
{
    snake_t *snake = (snake_t *)malloc(sizeof(snake_t));
    initSnake(snake, START_TAIL_SIZE, 10, 10);
    initFood(food);
    initscr();
    keypad(stdscr, TRUE); // Включаем F1, F2, стрелки и т.д.
    raw();                // Откдючаем line buffering
    noecho();             // Отключаем echo() режим при вызове getch
    curs_set(FALSE);      // Отключаем курсор
    mvprintw(0, 0, "Use arrows for control. Press 'F10' for EXIT");
    timeout(0); // Отключаем таймаут после нажатия клавиши в цикле
    int key_pressed = 0;
    while (key_pressed != STOP_GAME)
    {
        key_pressed = getch(); // Считываем клавишу
        changeDirection(snake, key_pressed);
        clear();
        refreshFood(food, snake);
        go(snake);
        // mvprintw(5, 5, "test\n");
        if (isCrush(snake))
        {
            printf("F A T A L I T Y ! ! !");
            mvprintw(10, 10, "F A T A L I T Y ! ! !");
            refresh();
            // delay_output(1000);
            // timeout(2000);// - не работает
            exit(1);
        }
        goTail(snake);
        timeout(2000); // Задержка при отрисовке
        timeout(300);  // Работает только последний вызов timeout
    }
    free(snake->tail);
    free(snake);
    endwin(); // Завершаем режим curses mod
    return 0;
}