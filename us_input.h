#ifndef H_US_INPUT
#define H_US_INPUT

#define MAXSIZE 1000
#define YELLOW  "\033[1;33m"


enum INPUT_STATUS
{
    END_OF_INPUT,
    CONTINUE_OF_INPUT,
    ERROR_OF_INPUT
};

const int CORRECT_NUMBER_OF_COEF = 3;

/*!
-----------------------------------
Binds user input and equation solution
-----------------------------------
*/
void startSolveKvadratka();


/*!
-----------------------------------
Produces formatted output depending on the number of roots

\param [in] nRoots number of roots
\param [in] x1     1-st root
\param [in] x2     2-nd root

------------------------------------
*/
void prettyPrintRoots(int, double, double);


/*!
-----------------------------------
 Processes user input, reads values ​​of equation arguments

 \param [in] pa_coef pointer on a-coeficient
 \param [in] pb_coef pointer on b-coeficient
 \param [in] pc_coef pointer on c-coeficient
 \return Status of input

-----------------------------------
*/
int userInput(double* a_coef, double* b_coef, double* c_coef);


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


#endif
