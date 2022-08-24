/*!
Tut text

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include <string.h>


#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)

const double EPS = 1e-8;
const int MAXSIZE = 1000;


enum Flags {
    NULL_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_SOL,
    WRONG = 0,
    CORRECT= 1
};

int isNull(double);
int solveLineyka(double, double, double*);
int solveKvadratka(double, double, double, double*, double*);
void pretyPrintRoots(int, double, double);
void clearBuffer();
int find_quit();
void test_SK();
void test_case(double, double, double, int, double, double);
int eqd(double, double);
void userInput();

//!---------------------------------------------
//!@param [in] a number to compare against zero
//!---------------------------------------------
int isNull(double a)
{
    return fabs(a) < EPS;
}

//!--------------------------------------------
//!@param [in]  a  a-coefficient
//!@param [in]  b  b-coefficient
//!@param [out] px pointer to the root
//!--------------------------------------------
int solveLineyka(double b, double c, double* px)
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
            return NULL_ROOTS;
        }
    }
    *px = -c / b;
    return 1;
}

//!--------------------------------------------
//!
//!@param [in]  a a-coefficient
//!@param [in]  b b-coefficient
//!@param [in]  c c-coefficient
//!@param [out] px1 pointer to the first root
//!@param [out] px2 pointer to the second root
//!--------------------------------------------
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

//-----------------------------------
//!@param [in] nRoots number of roots
//!@param [in] x1     1-st root
//!@param [in] x2     2-nd root
//------------------------------------
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


void clearBuffer()
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


void test_SK()
{

    test_case(0,    0,    0,    INF_SOL,  0, 0);
    test_case(1,    2,   -3,  TWO_ROOTS, -3, 1);
    test_case(5,    2,    8, NULL_ROOTS,  0, 0);
    test_case(1,    2,    1,   ONE_ROOT, -1, 0);
    test_case(1, 10.5, 13.5,  TWO_ROOTS, -9, -1.5);

}


void test_case(double a, double b, double c, int tnRoots, double tx1, double tx2)
{
    double x1 = NAN, x2 = NAN;
    int nRoots = solveKvadratka(a, b, c, &x1, &x2);
    int status = CORRECT;
    if (nRoots != tnRoots)
    {
        status = WRONG;
    }
    switch (nRoots)
    {
        case ONE_ROOT:
            status = (eqd(x1, tx1)) ? CORRECT : WRONG;
            break;
        case TWO_ROOTS:
            status = (eqd(x1, tx1) && eqd(x2, tx2)) ? CORRECT : WRONG;
            break;
        default:
            status = CORRECT;
    }
    if (status == WRONG)
    {
        printf("Failed:   nRoots = %d, x1 = %lg, x2 = %lg\n"
               "Expected: nRoots = %d, x1 = %lg, x2 = %lg\n"
             "With arguments a = %lg, b = %lg, c = %lg\n",
             nRoots, x1, x2, tnRoots, tx1, tx2, a, b, c);
    }
}

int eqd(double a, double b)
{
    return ((a < (b + EPS)) && (a > (b - EPS)));
}


void userInput()
{
   double a = NAN, b = NAN, c = NAN; //quadratic equation coefficients
    double x1 = NAN, x2 = NAN;        //equation roots
    int nRoots = 0;                   //number of roots of the equation
    int nCoeficients = 0;             //number of equation coefficients read
    printf("To end the program, enter quit\n");
    while (true)
    {
        printf("Enter the coefficients of the quadratic equation: ");
        nCoeficients = scanf("%lg %lg %lg", &a, &b, &c);
        if (nCoeficients != 3)
        {
            if (find_quit())
            {
                break;
            }
            clearBuffer();
            printf("Enter normal values\n"
            "For example: 1.4 3 -5.4\n");
            continue;
        }
        nRoots = solveKvadratka(a, b, c, &x1, &x2);
        pretyPrintRoots(nRoots, x1, x2);
    }
}


int main()
{
    userInput();
}
