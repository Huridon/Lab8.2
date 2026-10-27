#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int Task0(int n, char c1, char c2, char *line);
int Task1(int m, int n, int *count);
int Task1A(int m);
double Task2(double x);

double Home(double x_);

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // ---------- Task0 ----------
    int n0;
    char c1, c2;

    printf("Введите количество символов: ");
    scanf("%d", &n0);

    printf("Введите два символа через пробел: ");
    scanf(" %c %c", &c1, &c2);

    if (n0 >= 0)
    {
        char *line = (char *)malloc(2 * n0 + 3);
        if (line != NULL)
        {
            Task0(n0, c1, c2, line);
            printf("%s\n", line);
            free(line);
        }
    }
    else
    {
        printf("Ошибка: количество символов должно быть неотрицательным.\n");
    }

    // ---------- Task1 ----------
    int n1, m1, count, sum;

    printf("\nВведите значения m и n (m >= n): ");
    scanf("%d %d", &m1, &n1);

    sum = Task1(m1, n1, &count);

    for (int k = 1; k <= count; k++)
        printf("Выполнено %d раз\n", k);

    printf("Результат: %d\n", sum);

    // ---------- Task1A ----------
    int mA, terms;

    printf("\nВведите целое число m: ");
    scanf("%d", &mA);

    terms = Task1A(mA);

    for (int i = 0; i < terms; i++)
        printf("2^%-3d = %10.0f\n", i, pow(2, i));

    printf("Результат: %.1fK\n", mA / 1024.0);

    // ---------- Task2 ----------
    double x2, h, y;

    printf("\nФункция y = x^2 + 2*pi*cos(pi*x)\n");

    printf("Введите шаг табуляции: ");
    scanf("%lf", &h);

    if (h > 0)
    {
        printf("\n     x          f(x)\n");
        printf("--------------------------\n");

        for (x2 = 0.1; x2 <= 2.5 + h / 1000000.0; x2 += h)
        {
            y = Task2(x2);
            printf("%8.3f   %12.6f\n", x2, y);
        }
    }
    else
    {
        printf("Ошибка: шаг табуляции должен быть больше нуля (h > 0).\n");
    }

    // ---------- Домашняя работа ----------
    double x, a;

    printf("\nВведите значение x: ");
    scanf("%lf", &x);

    a = Home(x);

    if (isnan(a))
    {
        printf("\nОшибка: знаменатель равен нулю (x = 2, 4, 8, 16, 32 или 64).\n");
    }
    else
    {
        printf("\nРезультат вычислений:\n");
        printf("  x = %.5f\n", x);
        printf("  a = %.5f\n", a);
    }

    return 0;
}


int Task0(int n, char c1, char c2, char *line)
{
    int len = 0;

    if (n < 0)
        return -1;

    line[len++] = '+';

    for (int i = 0; i < n; i++)
    {
        if (i < (n + 1) / 2)
            line[len++] = c1;
        else
            line[len++] = c2;

        line[len++] = '!';
    }

    line[len++] = '+';
    line[len] = '\0';

    return len;
}


int Task1(int m, int n, int *count)
{
    int s = 0;
    int k = 0;

    for (int i = m; i >= n; i--)
    {
        s += i;
        k++;
    }

    *count = k;

    return s;
}


int Task1A(int m)
{
    double value = 1.0;
    int n;

    for (n = 0; value <= m; n++)
        value *= 2;

    return n;
}


double Task2(double x)
{
    return pow(x, 2) + 2 * M_PI * cos(M_PI * x);
}


double Home(double x_)
{
    double numerator = 1.0;
    double denominator = 1.0;

    for (int i = 1; i <= 6; i++)
    {
        numerator *= x_ - (pow(2, i) - 1);
        denominator *= x_ - pow(2, i);
    }

    if (fabs(denominator) < 1e-12)
        return NAN;

    return numerator / denominator;
}
