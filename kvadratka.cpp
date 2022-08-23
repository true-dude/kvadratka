#include <stdio.h>
#include <math.h>
#include <assert.h>


enum Flags {
    INF_SOL = 3
};

int solLineyka(double b, double c, double* px)
{
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(px != NULL);
    if (b == 0)
    {
        if (c == 0)
        {
            return INF_SOL;
        }
        else
        {
            return 0;
        }
    }
    *px = -c / b;
    return 1;
}

int solKvadratka(double a, double b, double c, double* px1, double* px2)
{
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(px1 != NULL);
    assert(px2 != NULL);
    assert(px1 != px2);
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                return INF_SOL;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return solLineyka(b, c, px1);
        }
    }
    double d = (b * b) - (4 * a * c);
    if (d < 0)
    {
        return 0;
    }
    if (d == 0)
    {
        *px1 = -b / (2 * a);
        return 1;
    }
    if (d > 0)
    {
        *px1 = (-b + sqrt(d)) / (2 * a);
        *px2 = (-b - sqrt(d)) / (2 * a);
        return 2;
    }
}



int main()
{
    double a = NAN, b = NAN, c = NAN; //коэффициенты квадратного уравнения
    double x1 = NAN, x2 = NAN;  //корни уравнения
    int nRoots = 0; //количество корней уравнения
    printf("Для завершения программы нажмите Ctrl + C\n");
    while (1)
    {
        printf("Введите коэффициенты квадратного уравнения: ");
        scanf("%lg %lg %lg", &a, &b, &c);
        nRoots = solKvadratka(a, b, c, &x1, &x2);
        switch(nRoots)
        {
            case 0:
                printf("Уравнение не имеет корней\n");
                break;
            case 1:
                printf("Уравнение имеет один корень: x = %.2lf\n", x1);
                break;
            case 2:
                printf("Уравнение имеет два корня: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
                break;
            case INF_SOL:
                printf("Уравнение имеет бесконечно много корней\n");
                break;
            default:
                printf("Программа завершилась с ошибкой :(\n");
        }
    }
}
