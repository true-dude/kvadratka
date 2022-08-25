#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "mylib.h"


#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)

/*!
--------------------------------------------
For the given coefficients of the linearal equation b c looks for its roots and writes x

\param [in]  b_coef b-coefficient
\param [in]  c_coef c-coefficient
\param [out] px pointer to the root
\return Number of roots

--------------------------------------------
*/
int solveLineyka(double b_coef, double c_coef, double* px)
{
    assert(std::isfinite(b_coef));
    assert(std::isfinite(c_coef));
    assert(px != NULL);
    if (isNull(b_coef))
    {
        if (isNull(c_coef))
        {
            return INF_SOL;
        }
        else
        {
            return NULL_ROOTS;
        }
    }
    *px = -c_coef / b_coef;
    return ONE_ROOT;
}

/*!
--------------------------------------------
For the given coefficients of the quadratic equation a b c looks for its roots and writes x1 and x2

\param [in]  a_coef a-coefficient
\param [in]  b_coef b-coefficient
\param [in]  c_coef c-coefficient
\param [out] px1 pointer to the first root
\param [out] px2 pointer to the second root
\return Number of roots

--------------------------------------------
*/
int solveKvadratka(double a_coef, double b_coef, double c_coef, double* px1, double* px2)
{
    assert(std::isfinite(a_coef));
    assert(std::isfinite(b_coef));
    assert(std::isfinite(c_coef));
    assert(px1 != NULL);
    assert(px2 != NULL);
    assert(px1 != px2);
    if (isNull(a_coef))
    {
        if (isNull(b_coef))
        {
            if (isNull(c_coef))
            {
                return INF_SOL;
            }
            else
            {
                return NULL_ROOTS;
            }
        }
        else
        {
            return solveLineyka(b_coef, c_coef, px1);
        }
    }
    double D = b_coef * b_coef - 4 * a_coef * c_coef;
    if (isNull(D))
    {
        *px1 = -b_coef / (2 * a_coef);
        return 1;
    }
    if (D < 0)
    {
        return NULL_ROOTS;
    }
    else
    {
        double sqrtD = sqrt(D);
        *px1 = (-b_coef + sqrtD) / (2 * a_coef);
        *px2 = (-b_coef - sqrtD) / (2 * a_coef);
        double tmp;
        tmp  = min(*px1, *px2);
        *px2 = max(*px1, *px2);
        *px1 = tmp;
        return TWO_ROOTS;
    }
}

#undef min
#undef max
