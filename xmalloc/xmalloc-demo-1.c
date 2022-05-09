#include <stdio.h>
#include <stdlib.h>
#include "xmalloc.h"

int main(void)
{
    void *x = xmalloc(1000);
    printf("1000 bytes allocated.\n");

    free(x);
    x = NULL;
    printf("memory freed.\n");

    x = xmalloc(0);
    printf("0 bytes allocated.\n");

    free(x);
    x = NULL;
    printf("memory freed.\n");

    return EXIT_SUCCESS;
}