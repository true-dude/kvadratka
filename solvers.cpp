#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "solvers.h"
#include "comp.h"


void swap(double* a, double* b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}


int solveLineyka(double b_coef, double c_coef, double* px)
{
    assert(std::isfinite(b_coef));
    assert(std::isfinite(c_coef));
    assert(px != NULL);

    if (isZero(b_coef))
    {
        return isZero(c_coef) ? INF_SOL : NULL_ROOTS;
    }

    *px = -c_coef / b_coef;

    return ONE_ROOT;
}


int solveKvadratka(double a_coef, double b_coef, double c_coef, double* px1, double* px2)
{
    assert(std::isfinite(a_coef));
    assert(std::isfinite(b_coef));
    assert(std::isfinite(c_coef));

    assert(px1 != NULL);
    assert(px2 != NULL);
    assert(px1 != px2);

    if (isZero(a_coef))
    {
        *px1 = 0;
        *px2 = 0;

        return solveLineyka(b_coef, c_coef, px1);
    }

    double D = b_coef * b_coef - 4 * a_coef * c_coef;

    if (isZero(D))
    {
        *px1 = -b_coef / (2 * a_coef);

        return ONE_ROOT;
    }

    if (D < 0)
    {
        *px1 = 0;
        *px2 = 0;
        return NULL_ROOTS;
    }

    double sqrtD = sqrt(D);
    *px1 = (-b_coef + sqrtD) / (2 * a_coef);
    *px2 = (-b_coef - sqrtD) / (2 * a_coef);

    if (*px1 > *px2)
    {
        swap(px1, px2);
    }

    return TWO_ROOTS;
}

