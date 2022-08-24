#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

const double EPS = 1e-8;
const int MAXSIZE = 1000;


enum Flags {
    NULL_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_SOL,
};

int isNull(double);
int solLineyka(double, double, double*);
int solKvadratka(double, double, double, double*, double*);
void pretyPrintRoots(int, double, double);
void readAllChars();
int find_quit();

int isNull(double a)
{
    return abs(a) < EPS;
}

int solLineyka(double b, double c, double* px)
{
    assert(std::isfinite(b));
    assert(std::isfinite(c));
    assert(px != NULL);
    if (isNull(b))
    {
        if (isNull(c))
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
    if (isNull(a))
    {
        if (isNull(b))
        {
            if (isNull(c))
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
    double d = b * b - 4 * a * c;
    if (isNull(d))
    {
        *px1 = -b / (2 * a);
        return 1;
    }
    if (d < 0)
    {
        return 0;
    }
    else
    {
        *px1 = (-b + sqrt(d)) / (2 * a);
        *px2 = (-b - sqrt(d)) / (2 * a);
        return 2;
    }
}

void pretyPrintRoots(int nRoots, double x1, double x2)
{
    switch(nRoots)
        {
            case NULL_ROOTS:
                printf("Уравнение не имеет корней\n");
                break;
            case ONE_ROOT:
                printf("Уравнение имеет один корень: x = %.2lf\n", x1);
                break;
            case TWO_ROOTS:
                printf("Уравнение имеет два корня: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
                break;
            case INF_SOL:
                printf("Уравнение имеет бесконечно много корней\n");
                break;
            default:
                printf("Программа завершилась с ошибкой :(\n");
        }
}


void readAllChars()
{
    int c;
    while ((c = getchar()) != EOF && c != '\n');
}

int find_quit()
{
    char s[MAXSIZE];
    scanf("%s", s);
    return strcmp(s, "quit") == 0;
}


int main()
{
    double a = NAN, b = NAN, c = NAN; //коэффициенты квадратного уравнения
    double x1 = NAN, x2 = NAN;        //корни уравнения
    int nRoots = 0;                   //количество корней уравнения
    int nCoeficients = 0;             //количество считанных коэффициентов уравнения
    printf("Для завершения программы введите quit\n");
    while (true)
    {
        printf("Введите коэффициенты квадратного уравнения: ");
        nCoeficients = scanf("%lg %lg %lg", &a, &b, &c);
        if (nCoeficients != 3)
        {
            if (find_quit())
            {
                break;
            }
            readAllChars();
            printf("Введите нормальные значения\n");
            continue;
        }
        nRoots = solKvadratka(a, b, c, &x1, &x2);
        pretyPrintRoots(nRoots, x1, x2);
    }
}
