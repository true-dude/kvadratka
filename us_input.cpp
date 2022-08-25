#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "mylib.h"

enum InputStatus {
    END_OF_INPUT,
    CONTINUE_OF_INPUT,
    ERROR_OF_INPUT
};

/*!
-----------------------------------
Produces formatted output depending on the number of roots

\param [in] nRoots number of roots
\param [in] x1     1-st root
\param [in] x2     2-nd root

------------------------------------
*/
void pretyPrintRoots(int nRoots, double x1, double x2)
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


/*!
-----------------------------------
Binds user input and equation solution
-----------------------------------
*/
void solve_K()
{
    double a_coef = NAN, b_coef = NAN, c_coef = NAN; //quadratic equation coefficients
    double x1 = NAN, x2 = NAN;                       //equation roots
    int nRoots = 0;                                  //number of roots of the equation
    printf("To end the program, enter quit\n");
    int statusOfInput = 0;
    while ((statusOfInput = userInput(&a_coef, &b_coef, &c_coef)) != END_OF_INPUT )
    {
        if (statusOfInput == CONTINUE_OF_INPUT)
        {
            nRoots = solveKvadratka(a_coef, b_coef, c_coef, &x1, &x2);
            pretyPrintRoots(nRoots, x1, x2);
        }
    }

}

/*!
-----------------------------------
 Processes user input, reads values ​​of equation arguments

 \param [in] pa_coef pointer on a-coeficient
 \param [in] pb_coef pointer on b-coeficient
 \param [in] pc_coef pointer on c-coeficient
 \return Status of input

-----------------------------------
*/
int userInput(double* pa_coef, double* pb_coef, double* pc_coef)
{
    printf("Enter the coefficients of the quadratic equation: ");
    int nCoeficients = scanf("%lg %lg %lg", pa_coef, pb_coef, pc_coef); //number of equation coefficients read
    if (nCoeficients != 3)
    {
        if (find_quit())
        {
            return END_OF_INPUT;
        }
        clearBuffer();
        printf("Enter normal values\n"
        "For example: 1.4 3 -5.4\n");
        return ERROR_OF_INPUT;
    }
    return CONTINUE_OF_INPUT;
}

/*!
-----------------------------------
Cleans thr booth of the car
-----------------------------------
*/
void clearBuffer()
{
    int c;
    while ((c = getchar()) != EOF && c != '\n');
}

#define MAXSIZE 1000

/*!
-----------------------------------
Looks for the quit keyword in user input

\return True if it find the word "quit" else false

-----------------------------------
*/
int find_quit()
{
    char s[MAXSIZE];
    scanf("%s", s);
    return strcmp(s, "quit") == 0;
}

#undef MAXSIZE
