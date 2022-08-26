#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "us_input.h"
#include "tests.h"
#include "parse_cmd.h"



void parseCmdLine(int argc, char *argv[])
{
    while (argc > 1)
    {

        if (strcmp(argv[1], "-s") == 0)
        {
            startSolveKvadratka();
        }

        else if (strcmp(argv[1], "-t") == 0)
        {
            testSK();
        }

        else
        {
            printf("%sNo command %s\n", YELLOW, argv[1]);
        }

    }
}


int main(int argc, char *argv[])
{
    parseCmdLine(argc, argv);

    return 0;
}

