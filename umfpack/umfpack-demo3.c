#include <suitesparse/umfpack.h>
#include <stdio.h>
#include "array.h"
#include "sparse.h"

static void error_and_exit(int status, const char *file, int line)
{
    fprintf(stderr, "*** file %s, line %d: ", file, line);
    switch (status) {
        case UMFPACK_ERROR_out_of_memory:
            fprintf(stderr, "out of memory!\n");
            break;
        case UMFPACK_WARNING_singular_matrix:
            fprintf(stderr, "matrix is singular!\n");
            break;
        default:
            fprintf(stderr, "UMFPACK error code %d\n", status);
    }
    exit(EXIT_FAILURE);
}

int main(void)
{
    void *Symbolic, *Numeric;
    double *b, *x, *Ax;
    int *Ap, *Ai;
    int n = 5;
    int nz;

    // ... allocate memory for the matrix a and the vectors b and x ...
    make_vector(b, n);
    make_vector(x, n);

    // ... populate the matrix a and vector b with the given numbers ...
    int N = 20, k = 0; // N = 20 is an overestimate; N = 12 will do
    int *Ti, *Tj;
    double *Tx;
    make_vector(Ti, N);
    make_vector(Tj, N);
    make_vector(Tx, N);
    Ti[k] = 0; Tj[k] = 0; Tx[k] = 2.0; k++; // the (0,0) entry is 2.0
    Ti[k] = 0; Tj[k] = 1; Tx[k] = 3.0; k++; // the (0,1) entry is 3.0
    Ti[k] = 1; Tj[k] = 0; Tx[k] = 3.0; k++; // the (1,0) entry is 3.0
    Ti[k] = 1; Tj[k] = 2; Tx[k] = 4.0; k++;
    Ti[k] = 1; Tj[k] = 4; Tx[k] = 6.0; k++;
    Ti[k] = 2; Tj[k] = 1; Tx[k] = -1.0; k++;
    Ti[k] = 2; Tj[k] = 2; Tx[k] = -3.0; k++;
    Ti[k] = 2; Tj[k] = 3; Tx[k] = 2.0; k++;
    Ti[k] = 3; Tj[k] = 2; Tx[k] = 1.0; k++;
    Ti[k] = 4; Tj[k] = 1; Tx[k] = 4.0; k++;
    Ti[k] = 4; Tj[k] = 2; Tx[k] = 2.0; k++;
    Ti[k] = 4; Tj[k] = 4; Tx[k] = 1.0; k++;

    b[0] = 8;
    b[1] = 45;
    b[2] = -3;
    b[3] = 3;
    b[4] = 19;

    nz = k;

    printf("matrix is %dx%d, nz = %d\n\n", n, n, nz);
    printf("b = ");
    print_vector("%7.3f ", b, n);
    putchar('\n');

    // ... allocate memory for the vectors Ap, Ai, and Ax ...
    make_vector(Ap, n + 1);
    make_vector(Ai, N);
    make_vector(Ax, N);

    // populate the CCS vectors
    int status = umfpack_di_triplet_to_col(n, n, k, Ti, Tj, Tx, Ap, Ai, Ax, NULL);
    if (status != UMFPACK_OK)
        error_and_exit(status, __FILE__, __LINE__);

    free_vector(Ti);
    free_vector(Tj);
    free_vector(Tx);

    // ... print out Ap, Ai, Ax ...
    printf("Ap = ");
    print_vector("%7d", Ap, n + 1);
    printf("Ai = ");
    print_vector("%7d", Ai, nz);
    printf("Ax = ");
    print_vector("%7.3f", Ax, nz);
    putchar('\n');

    status = umfpack_di_symbolic(n, n, Ap, Ai, Ax, &Symbolic, NULL, NULL);
    if (status != UMFPACK_OK)
        error_and_exit(status, __FILE__, __LINE__);
    status = umfpack_di_numeric(Ap, Ai, Ax, Symbolic, &Numeric, NULL, NULL);
    if (status != UMFPACK_OK)
        error_and_exit(status, __FILE__, __LINE__);
    status = umfpack_di_solve(UMFPACK_A, Ap, Ai, Ax, x, b, Numeric, NULL, NULL);
    if (status != UMFPACK_OK)
        error_and_exit(status, __FILE__, __LINE__);

    // ... print out x ...
    printf("x = ");
    print_vector("%7.3f ", x, n);
    putchar('\n');

    umfpack_di_free_symbolic(&Symbolic);
    umfpack_di_free_numeric(&Numeric);

    // ... also free the allocated memory for a, b, x, Ap, Ai, Ax ...
    free_vector(b);
    free_vector(x);
    free_vector(Ap);
    free_vector(Ai);
    free_vector(Ax);

    return 0;
}