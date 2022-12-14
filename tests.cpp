#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tests.h"
#include "solvers.h"
#include "comp.h"


int testSK()
{
    char fileName[] = "tests.txt";
    FILE* fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        printf(RED "File %s not found\n", fileName);
        return FILE_OPEN_ERROR;
    }

    int right_n_roots = 0;
    double a_coef = NAN, b_coef = NAN, c_coef = NAN;
    double right_x1 = NAN, right_x2 = NAN;

    do
    {
        int num_of_args = fscanf(fp, "%lg %lg %lg %d %lg %lg",
                                &a_coef, &b_coef, &c_coef, &right_n_roots, &right_x1, &right_x2);
        printf("%d\n", right_n_roots);
        testCase(a_coef, b_coef, c_coef, right_n_roots, right_x1, right_x2);

        if (num_of_args == EOF)
        {
            printf(GREEN "Testing completed\n");
            break;
        }

        if (num_of_args != SIX_ARGUMENTS)
        {
            printf(RED "File read error\n");
            break;
        }

    } while (true);

    fclose(fp);

    return SUCCESSFUL_TESTING;
}


void testCase(double a_coef, double b_coef, double c_coef, int right_n_roots, double right_x1, double right_x2)
{
    double x1 = NAN, x2 = NAN;
    int n_roots = solveKvadratka(a_coef, b_coef, c_coef, &x1, &x2);

    int status_case = CORRECT;

    if (right_n_roots != n_roots)
    {
        status_case = WRONG;
    }

    switch (right_n_roots)
    {
        case ONE_ROOT:
            status_case = (compareDouble(x1, right_x1)) ? CORRECT : WRONG;
            break;

        case TWO_ROOTS:
            status_case = (compareDouble(x1, right_x1) && compareDouble(x2, right_x2)) ? CORRECT : WRONG;
            break;

        case INF_SOL:
            status_case = (compareDouble(x1, right_x1) && compareDouble(x2, right_x2)) ? CORRECT : WRONG;
            break;

        case NULL_ROOTS:
            status_case = (compareDouble(x1, right_x1) && compareDouble(x2, right_x2)) ? CORRECT : WRONG;
            break;

        default:
            printf(RED "Indefinite number of roots\n");
    }

    if (status_case == CORRECT)
    {
        printf(GREEN "Testing with arguments a = %lg, b = %lg, c = %lg passed succesfuly\n",
                                             a_coef,  b_coef,   c_coef);
    }

    if (status_case == WRONG)
    {
        printf(RED "Failed: nRoots = %d, x1 = %lg, x2 = %lg\n"
                   "Expected: nRoots = %d, x1 = %lg, x2 = %lg\n"
                   "With coeficients a = %lg, b = %lg, c = %lg\n",
                   n_roots, x1, x2,
                   right_n_roots, right_x1, right_x2,
                   a_coef, b_coef, c_coef);
    }
}
