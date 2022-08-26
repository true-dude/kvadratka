#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "comp.h"

const double EPS = 1e-8;


int isZero(double a)
{
    return fabs(a) < EPS;
}


int compareDouble(double a, double b)
{
    return fabs(a - b) < EPS;
}
