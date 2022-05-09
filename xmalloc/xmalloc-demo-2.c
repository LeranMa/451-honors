#include <stdio.h>
#include <stdlib.h>
#include "xmalloc.h"

int main(void)
{
    void *x = NULL;
    int ct = 0;
    while(1)
    {
        x = xmalloc(1000000000);
        printf("%d: 1000000000 bytes allocated.\n", ct++);
    }

    return EXIT_SUCCESS;
}