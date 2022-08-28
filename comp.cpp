#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "comp.h"


int isZero(double a)
{
    return fabs(a) < EPS;
}


int compareDouble(double a, double b)
{
    return fabs(a - b) < EPS;
}
