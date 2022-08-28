#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "us_input.h"
#include "solvers.h"


void prettyPrintRoots(int nRoots, double x1, double x2)
{
    switch(nRoots)
    {
        case NULL_ROOTS:
            printf("The equation has no roots\n");
            break;

        case ONE_ROOT:
            printf("The equation has one root: x = %.2lf\n", x1);
            break;

        case TWO_ROOTS:
            printf("The equation has two roots: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
            break;

        case INF_SOL:
            printf("The equation has infinitely many roots\n");
            break;

        default:
            printf("The program ended with an error :(\n");
    }
}



void startSolveKvadratka()
{
    double a_coef = NAN, b_coef = NAN, c_coef = NAN; //quadratic equation coefficients
    double x1 = NAN, x2 = NAN;                       //equation roots
    int n_roots = 0;                                  //number of roots of the equation

    printf("To end the program, enter quit\n");

    int status_of_input = userInput(&a_coef, &b_coef, &c_coef);

    while (status_of_input != END_OF_INPUT)
    {
        if (status_of_input == CONTINUE_OF_INPUT)
        {
            n_roots = solveKvadratka(a_coef, b_coef, c_coef, &x1, &x2);
            prettyPrintRoots(n_roots, x1, x2);
        }

        status_of_input = userInput(&a_coef, &b_coef, &c_coef);
    }

}


int userInput(double* pa_coef, double* pb_coef, double* pc_coef)
{
    printf("Enter the coefficients of the quadratic equation: ");

    int n_coeficients = scanf("%lg %lg %lg", pa_coef, pb_coef, pc_coef); //number of equation coefficients read

    if (n_coeficients != CORRECT_NUMBER_OF_COEF)
    {
        if (findQuit())
        {
            return END_OF_INPUT;
        }

        clearBuffer();

        printf("Enter normal values\n"
               "For example: 1.4 3 -5.4\n");

        return ERROR_OF_INPUT;
    }

    clearBuffer();

    return CONTINUE_OF_INPUT;
}


void clearBuffer()
{
    int c = getchar();

    while (c != EOF && c != '\n')
    {
        c = getchar();
    }
}


int findQuit()
{
    char s[MAXSIZE] = {0};
    scanf("%s", s);

    char quit_flag[] = "quit";
    return (strcmp(s, quit_flag) == 0);
}
