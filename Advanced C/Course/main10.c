#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int count = 0; // количество итераций

float root(float (*f)(float), float (*g)(float), float a, float b, float eps1);
float integral(float (*f)(float), float a, float b, float eps2);
float func1(float x);
float func2(float x);
float func3(float x);
float testf(float x);
float function(float (*func)(float), float x);
void displayGraph(void);

int main(int argc, char *argv[])
{
    float eps1 = 0.01;
    float eps2 = 0.01;
    displayGraph();
    float point1 = root(func1, func3, 0, 3, eps1);
    float point2 = root(func2, func3, 2, 3.5, eps1);
    float point3 = root(func1, func2, 1, 5, eps1);

    float integral_sum = integral(func1, point1, point3, eps2);
    float integral_1 = integral(func3, point1, point2, eps2);
    float integral_2 = integral(func2, point2, point3, eps2);
    printf("\nR E S U L T = %.4f\n\n", integral_sum - integral_1 - integral_2);
    for (size_t i = 0; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
            case 'h':
                printf("help:\n");
                printf("-a printing the coordinates of the abscissa\n");
                printf("-n summary number of iterations\n");
                printf("-i printing the value of integrals\n\n");
                break;
            case 'a':
                printf("Point 1 = %15.3f point 2 = %8.3f point 3 = %8.3f\n", point1, point2, point3);
                break;
            case 'i':
                printf("Integral summary = %6.3f integral 1 = %5.3f integral 2 = %5.3f\n", integral_sum, integral_1, integral_2);
                break;
            case 'n':
                printf("Summary number of iterations: %d", count);
                break;
            default:
                printf("Argument is not recognised\n\n");
                break;
            }
        }
    }
    return 0;
}

float root(float (*f)(float), float (*g)(float), float a, float b, float eps1)
{
    float min_root = fabs(a);
    float min_root_delta = fabs(a - b);
    float delta;
    float step = 0.01;
    for (float x = a; x <= b; x += eps1, count++)
    {
        delta = fabs(f(x) - g(x));
        if (delta < min_root_delta) // поиск наименьшей разницы между значениями функций
        {
            min_root_delta = delta;
            min_root = x;
        }
    }
    return min_root;
}

float integral(float (*f)(float), float a, float b, float eps2)
{
    float sum = 0;
    unsigned int steps_count = fabs(b - a) / eps2; // вычисление количества шагов, чтобы обеспечить требуемую точность
    float delta = fabs(b - a) / steps_count;       // вычисление размера одного приращения для обеспечения требуемой точности
    for (size_t i = 0; i < steps_count; i++)
    {
        sum += f(a);
        a += delta;
    }
    return sum * delta;
}

float func1(float x)
{
    return 0.6 * x + 3;
}

float func2(float x)
{
    return ((x - 2) * (x - 2) * (x - 2)) - 1;
}

float func3(float x)
{
    return 3 / x;
}

float function(float (*func)(float), float x)
{
    return func(x);
}

float testf(float x)
{
    return 2;
}

void displayGraph(void)
{
    FILE *gnuplotPipe = _popen("gnuplot -persistent", "w");
    if (gnuplotPipe)
    {
        FILE *dataFile1 = fopen("f1", "w");
        FILE *dataFile2 = fopen("f2", "w");
        FILE *dataFile3 = fopen("f3", "w");
        float step = 0.1; // приращение х
        for (float x = -10.0; x <= 10.0; x += step)
        {
            float f1 = function(func1, x);
            float f2 = function(func2, x);
            float f3 = function(func3, x);
            fprintf(dataFile1, "%f %f\n", x, f1);
            fprintf(dataFile2, "%f %f\n", x, f2);
            fprintf(dataFile3, "%f %f\n", x, f3);
        }
        fclose(dataFile1);
        fclose(dataFile2);
        fclose(dataFile3);

        fprintf(gnuplotPipe, "set title 'f1(x) = 0.6x + 3,     f2(x) = (x - 2)^3 - 1,     f3(x) = 3/x'\n");
        fprintf(gnuplotPipe, "set grid\n");
        fprintf(gnuplotPipe, "set xrange[-10:10]\n");
        fprintf(gnuplotPipe, "set yrange[-10:10]\n");
        fprintf(gnuplotPipe, "set xlabel 'x'\n");
        fprintf(gnuplotPipe, "set ylabel 'y'\n");
        fprintf(gnuplotPipe, "plot 'f1' with lines lc rgb 'red', 'f2' with lines lc rgb 'green', 'f3' with lines lc rgb 'blue', 0 with lines lc 'black'\n");

        fflush(gnuplotPipe);
        _pclose(gnuplotPipe);
    }
    else
    {
        fprintf(stderr, "Gnuplot not found or could not be started.\n");
    }
}