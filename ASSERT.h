#include <stdio.h>

#define ASSERT(condition)                                            \
        if (!(condition))                                            \
            printf("Error in %s in %d line\n"                        \
            "Assertion \'%s\'\n",                                    \
            __FILE__, __LINE__, #condition);
