#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "mylib.h"

const int SIX_ARGUMENTS = 6;
const char* RED = "\033[1;31m";

/*!
---------------------------------------------
Tests solveKvadratka()
---------------------------------------------
*/
void test_SK()
{
    char fileName[] = "tests.txt";
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("%sFile %s not found\n", RED, fileName);
        abort();
    }

    int tnRoots = 0;
    double a_coef = NAN, b_coef = NAN, c_coef = NAN;
    double tx1 = NAN, tx2 = NAN;
    int n = 0;
    while ((n = fscanf(fp, "%lg %lg %lg %d %lg %lg", &a_coef, &b_coef, &c_coef, &tnRoots, &tx1, &tx2)) != EOF &&
            n == SIX_ARGUMENTS)
    {
        test_case(a_coef, b_coef, c_coef, tnRoots, tx1, tx2);
    }

    fclose(fp);
}

/*!
---------------------------------------------
Tests a single case

\param a-coef  a-coeficient
\param b-coef  b-coeficient
\param c-coef  c-coeficient
\param tnRoots correct number of roots
\param tx1     correct value of the 1-st root
\param tx2     correct value of the 2-nd root
\return Test status

---------------------------------------------
*/
void test_case(double a_coef, double b_coef, double c_coef, int tnRoots, double tx1, double tx2)
{
    double x1 = NAN, x2 = NAN;
    int nRoots = solveKvadratka(a_coef, b_coef, c_coef, &x1, &x2);
    int status = CORRECT;

    if (nRoots != tnRoots)
    {
        status = WRONG;
    }

    switch (nRoots)
    {
        case ONE_ROOT:
            status = (compareDouble(x1, tx1)) ? CORRECT : WRONG;
            break;

        case TWO_ROOTS:
            status = (compareDouble(x1, tx1) && compareDouble(x2, tx2)) ? CORRECT : WRONG;
            break;

        default:
            status = CORRECT;
    }

    if (status == WRONG)
    {
        printf("%sFailed:   nRoots = %d, x1 = %lg, x2 = %lg\n"
               "Expected: nRoots = %d, x1 = %lg, x2 = %lg\n"
             "With arguments a = %lg, b = %lg, c = %lg\n",
             RED, nRoots, x1, x2, tnRoots, tx1, tx2, a_coef, b_coef, c_coef);
    }
}
