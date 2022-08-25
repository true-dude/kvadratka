#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "mylib.h"

const double EPS = 1e-8;

/*!
---------------------------------------------
Compares a number double type with zero

\param [in] a number to compare against zero
\return true if a if null else false

---------------------------------------------
*/
int isNull(double a)
{
    return fabs(a) < EPS;
}

/*!
---------------------------------------------
Compares two numbers double type

\param [in] a 1-st number
\param [in] b 2-nd number
\return true if the numbers are equal else false

---------------------------------------------
*/
int compareDouble(double a, double b)
{
    return ((a < (b + EPS)) && (a > (b - EPS)));
}
