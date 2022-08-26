#ifndef H_SOLVERS
#define H_SOLVERS

/*!
--------------------------------------------
Swaps values

\param [in] a 1-st value
\param [in] b 2-nd value

--------------------------------------------
*/
void swap(double* a, double* b);

/*!
--------------------------------------------
For the given coefficients of the linearal equation b c looks for its roots and writes x

\param [in]  b_coef b-coefficient
\param [in]  c_coef c-coefficient
\param [out] px pointer to the root
\return Number of roots

--------------------------------------------
*/
int solveLineyka(double b_coef, double c_coef, double* px);


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
int solveKvadratka(double a_coef, double b_coef, double c_coef, double* px1, double* px2);


enum NUMBER_OF_ROOTS
{
    NULL_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2,
    INF_SOL    = 3
};

#endif
