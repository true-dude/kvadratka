#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "mylib.h"
#include "ASSERT.h"

const char* YELLOW = "\033[1;33m";

int main(int argc, char *argv[])
{
    ASSERT(2 == 3);
    while (--argc > 0)
    {
        if (argc == 1)
        {
            if (strcmp(argv[1], "solve") == 0)
            {
                solve_K();
            }
            else if (strcmp(argv[1], "test") == 0)
            {
                test_SK();
            }
            else
            {
                printf("%sNo command %s\n", YELLOW, argv[1]);
            }
        }
    }
    return 0;
}

