#ifndef H_TESTS
#define H_TESTS

#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"

const int SIX_ARGUMENTS = 6;

enum STATUS_TESTS
{
    FILE_OPEN_ERROR,
    SUCCESSFUL_TESTING
};

enum STATUS_ANSWER
{
    WRONG      = 0,
    CORRECT    = 1
};

/*!
---------------------------------------------
Tests solveKvadratka()

\return Testin status

---------------------------------------------
*/
int testSK();


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
void testCase(double a_coef, double b_coef, double c_coef, int, double right_x1, double right_x2);


#endif
