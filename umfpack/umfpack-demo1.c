#include <suitesparse/umfpack.h>
#include <stdio.h>
#include "array.h"
#include "sparse.h"

int main(void)
{
    void *Symbolic, *Numeric;
    double **a;
    double *b, *x, *Ax;;
    int *Ap, *Ai;
    int n = 5;
    int i, j, nz;

    // ... allocate memory for the matrix a and the vectors b and x ...
    make_matrix(a, n, n);
    make_vector(b, n);
    make_vector(x, n);

    // ... populate the matrix a and vector b with the given numbers ...
    a[0][0] = 2;
    a[0][1] = 3;
    a[0][2] = 0;
    a[0][3] = 0;
    a[0][4] = 0;
    a[1][0] = 3;
    a[1][1] = 0;
    a[1][2] = 4;
    a[1][3] = 0;
    a[1][4] = 6;
    a[2][0] = 0;
    a[2][1] = -1;
    a[2][2] = -3;
    a[2][3] = 2;
    a[2][4] = 0;
    a[3][0] = 0;
    a[3][1] = 0;
    a[3][2] = 1;
    a[3][3] = 0;
    a[3][4] = 0;
    a[4][0] = 0;
    a[4][1] = 4;
    a[4][2] = 2;
    a[4][3] = 0;
    a[4][4] = 1;

    b[0] = 8;
    b[1] = 45;
    b[2] = -3;
    b[3] = 3;
    b[4] = 19;

    // ... compute nz as in Project Sparse Matrix ...
    nz = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                nz++;
            }
        }
    }

    // ... print out a, b, and nz as in Project Sparse Matrix ...
    printf("The sparse matrix is\n");
    print_matrix("%7.3f ", a, n, n);
    printf("matrix is %dx%d, nz = %d\n\n", n, n, nz);

    printf("b = ");
    print_vector("%7.3f ", b, n);
    putchar('\n');

    // ... allocate memory for the vectors Ap, Ai, and Ax ...
    make_vector(Ap, n + 1);
    make_vector(Ai, nz);
    make_vector(Ax, nz);

    sparse_pack(a, n, n, Ap, Ai, Ax); // populate the CCS vectors

    // ... print out Ap, Ai, Ax ...
    printf("Ap = ");
    print_vector("%7d", Ap, n + 1);
    printf("Ai = ");
    print_vector("%7d", Ai, nz);
    printf("Ax = ");
    print_vector("%7.3f", Ax, nz);
    putchar('\n');

    umfpack_di_symbolic(n, n, Ap, Ai, Ax, &Symbolic, NULL, NULL);
    umfpack_di_numeric(Ap, Ai, Ax, Symbolic, &Numeric, NULL, NULL);
    umfpack_di_solve(UMFPACK_A, Ap, Ai, Ax, x, b, Numeric, NULL, NULL);

    // ... print out x ...
    printf("x = ");
    print_vector("%7.3f ", x, n);
    putchar('\n');

    umfpack_di_free_symbolic(&Symbolic);
    umfpack_di_free_numeric(&Numeric);

    // ... also free the allocated memory for a, b, x, Ap, Ai, Ax ...
    free_matrix(a);
    free_vector(b);
    free_vector(x);
    free_vector(Ap);
    free_vector(Ai);
    free_vector(Ax);

    return 0;
}