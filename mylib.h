#ifndef H_MYLIB
#define H_MYLIB

int isNull(double);
void pretyPrintRoots(int, double, double);
void clearBuffer();
int findQuit();
void test_SK();
void test_case(double, double, double, int, double, double);
int compareDouble(double, double);
int userInput(double*, double*, double*);
int solveLineyka(double, double, double*);
int solveKvadratka(double, double, double, double*, double*);
void solve_K();



enum NumberOfRoots {
    NULL_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_SOL,
    WRONG = 0,
    CORRECT= 1
};

#endif
