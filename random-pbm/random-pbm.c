#include <stdio.h>
#include <stdlib.h>
#include "array.h"

static inline int random(int n)
{
    return rand()/(RAND_MAX/n + 1);
}

static int write_pbm(char **M, int m, int n, char *outfile)
{
    FILE *fout = fopen(outfile, "w");
    if (fout == NULL)
    {
        fprintf(stderr, "failed to open %s\n", outfile);
        return 0;
    }

    fprintf(fout, "P1\n%d %d\n", n, m);
    print_matrix(fout, "%d ", M, m, n);
    return 1;
}

static char **make_random_matrix(int m, int n, double f)
{
    char **M;
    int i, j, k;
    make_matrix(M, m, n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            M[i][j] = 0;
    k = 0;
    while (k < f*m*n) {
        i = random(m);
        j = random(n);
        if (M[i][j] == 0) {
            M[i][j] = 1;
            k++;
        }
    }
    return M;
}

static void show_usage(char *progname)
{
    printf("Usage: %s m n s f outfile\n"
           "    writes an mxn random bitmap to a file named 'outfile'\n"
           "    f: fill ratio 0.0 <= f <= 1.0\n"
           "    s: integer >= 1: seeds the random number generator\n", progname);
}

int main(int argc, char **argv)
{
    int m, n, s;
    double f;
    char **M;
    char *outfile;
    char *endptr;
    int status = EXIT_FAILURE;

    if (argc != 6) {
        show_usage(argv[0]);
        return EXIT_FAILURE;
    }
    m = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || m < 1) {
        show_usage(argv[0]);
        return status;
    }
    n = strtol(argv[2], &endptr, 10);
    if (*endptr != '\0' || n < 1) {
        show_usage(argv[0]);
        return status;
    }
    s = strtol(argv[3], &endptr, 10);
    if (*endptr != '\0' || s < 1) {
        show_usage(argv[0]);
        return status;
    }
    f = strtod(argv[4], &endptr);
    if (*endptr != '\0' || s > 1 || s < 0) {
        show_usage(argv[0]);
        return status;
    }
    outfile = argv[5];

    srand(s);
    M = make_random_matrix(m, n, f);

    if (write_pbm(M, m, n, outfile) == 1)
        status = EXIT_SUCCESS;
    free_matrix(M);
    return status;
}