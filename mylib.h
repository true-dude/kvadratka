#ifndef H_MYLIB
#define H_MYLIB

/*!
---------------------------------------------
Compares a number double type with zero

\param [in] a number to compare against zero
\return true if a if null else false

---------------------------------------------
*/

// isZero
int isNull(double);


/*!
-----------------------------------
Produces formatted output depending on the number of roots

\param [in] nRoots number of roots
\param [in] x1     1-st root
\param [in] x2     2-nd root

------------------------------------
*/
void pretyPrintRoots(int, double, double);


/*!
-----------------------------------
Cleans the booth of the buffer
-----------------------------------
*/
void clearBuffer();


/*!
-----------------------------------
Looks for the quit keyword in user input

\return True if it find the word "quit" else false

-----------------------------------
*/
int findQuit();


/*!
---------------------------------------------
Tests solveKvadratka()
---------------------------------------------
*/
void testSK();


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
// code???
void test_case(double, double, double, int, double, double);


/*!
---------------------------------------------
Compares two numbers double type

\param [in] a 1-st number
\param [in] b 2-nd number
\return true if the numbers are equal else false

---------------------------------------------
*/
int compareDouble(double, double);


/*!
-----------------------------------
 Processes user input, reads values ​​of equation arguments

 \param [in] pa_coef pointer on a-coeficient
 \param [in] pb_coef pointer on b-coeficient
 \param [in] pc_coef pointer on c-coeficient
 \return Status of input

-----------------------------------
*/
int userInput(double*, double*, double*);


/*!
--------------------------------------------
For the given coefficients of the linearal equation b c looks for its roots and writes x

\param [in]  b_coef b-coefficient
\param [in]  c_coef c-coefficient
\param [out] px pointer to the root
\return Number of roots

--------------------------------------------
*/
int solveLineyka(double, double, double*);


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
// double a, double b, double c, double *x1, double *x2??
int solveKvadratka(double, double, double, double*, double*);


/*!
-----------------------------------
Binds user input and equation solution
-----------------------------------
*/
// ??
// choose_start_mode()
void startSolveKvadratka();


/*!
-----------------------------------
Search extra characters in input

\return True if extra characters are else false

-----------------------------------
*/
// ????
int findExtraChars();

// NUMBER_OF_ROOTS

enum NumberOfRoots
{
    NULL_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2,
    INF_SOL    = 3
}
    // enum STATUS {}
enum STATUS_ANSWER
{
    WRONG      = 0,
    CORRECT    = 1
};

#endif
