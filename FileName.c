#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

int Task0(int n, char c1, char c2);
int Task1(int m, int n);
double Task1A(int m);
int Task2(double h);

double Home(double x_);

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Task0
    int n0, len;
    char c1, c2;

    printf("Введите количество символов: ");
    scanf("%d", &n0);

    printf("Введите два символа через пробел: ");
    scanf(" %c %c", &c1, &c2);

    len = Task0(n0, c1, c2);
    printf("Выведено символов: %d\n", len);

    // Task1
    int m1, n1, sum;

    printf("\nВведите значения m и n (m >= n): ");
    scanf("%d %d", &m1, &n1);

    sum = Task1(m1, n1);

    printf("Выполнено %d раз\n", m1 - n1 + 1);
    printf("Результат: %d\n", sum);

    // Task1A
    int m2;
    double kilo;

    printf("\nВведите целое число m: ");
    scanf("%d", &m2);

    kilo = Task1A(m2);
    printf("Результат: %.1fK\n", kilo);

    // Task2
    double h;
    int rows;

    printf("\nФункция y = x^2 + 2*pi*cos(pi*x)\n");
    printf("Введите шаг табуляции: ");
    scanf("%lf", &h);

    if (h > 0)
    {
        rows = Task2(h);
        printf("Количество строк таблицы: %d\n", rows);
    }
    else
    {
        printf("Ошибка: шаг табуляции должен быть больше нуля\n");
    }

    //Домашняя работа:

    double x, a;
    int ok = 1;

    printf("\nВведите значение x: ");
    scanf("%lf", &x);


    for (int i = 1; i <= 6; i++)
    {
        if (fabs(x - pow(2, i)) < 1e-9)
            ok = 0;
    }

    if (ok)
    {
        a = Home(x);

        printf("\nРезультат вычислений:\n");
        printf("  x = %.5f\n", x);
        printf("  a = %.5f\n", a);
    }
    else
    {
        printf("Ошибка: знаменатель равен нулю при x = 2, 4, 8, 16, 32, 64\n");
    }

    return 0;
}

int Task0(int n, char c1, char c2)
{
    int count = 0;

    putchar('+');
    count++;

    for (int i = 0; i < n; i++)
    {
        if (i < (n + 1) / 2)
            putchar(c1);
        else
            putchar(c2);

        putchar('!');
        count += 2;
    }

    putchar('+');
    putchar('\n');
    count++;

    return count;
}

int Task1(int m, int n)
{
    int s = 0;

    for (int i = m; i >= n; i--)
    {
        s += i;
    }

    return s;
}

double Task1A(int m)
{
    double value = 1.0;

    for (int n = 0; value <= m; n++)
    {
        printf("2^%-3d = %10.0f\n", n, value);
        value *= 2;
    }

    return m / 1024.0;
}

int Task2(double h)
{
    double x, y;
    int count = 0;

    if (h <= 0)
        return 0;

    printf("\n     x          f(x)\n");
    printf("--------------------------\n");

    for (x = 0.1; x <= 2.5 + h / 1000000.0; x += h)
    {
        y = pow(x, 2) + 2 * M_PI * cos(M_PI * x);
        printf("%8.3f   %12.6f\n", x, y);
        count++;
    }

    return count;
}

double Home(double x_)
{
    double numerator = 1.0;
    double denominator = 1.0;
    double a;

    for (int i = 1; i <= 6; i++)
    {
        numerator *= x_ - (pow(2, i) - 1);
        denominator *= x_ - pow(2, i);
    }

    a = numerator / denominator;

    return a;
}
