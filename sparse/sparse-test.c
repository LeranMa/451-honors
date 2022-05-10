#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "sparse.h"

int main(void)
{
    int m = 4, n = 5, nz = 0;
    double **a;
    make_matrix(a, m, n);
    a[0][0] = 0;
    a[0][1] = 7;
    a[0][2] = 0;
    a[0][3] = 0;
    a[0][4] = 1;
    a[1][0] = 0;
    a[1][1] = 4;
    a[1][2] = 0;
    a[1][3] = 3;
    a[1][4] = 0;
    a[2][0] = 6;
    a[2][1] = 6;
    a[2][2] = 5;
    a[2][3] = 1;
    a[2][4] = 4;
    a[3][0] = 5;
    a[3][1] = 5;
    a[3][2] = 0;
    a[3][3] = 0;
    a[3][4] = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                nz++;
            }
        }
    }

    printf("The sparse matrix is\n");
    print_matrix("%7.3f ", a, m, n);
    printf("matrix is %dx%d, nz = %d\n\n", m, n, nz);

    int *Ap, *Ai;
    make_vector(Ap, n + 1);
    make_vector(Ai, nz);
    double *Ax;
    make_vector(Ax, nz);

    sparse_pack(a, m, n, Ap, Ai, Ax);
    printf("Ap = ");
    print_vector("%7d", Ap, n + 1);
    printf("Ai = ");
    print_vector("%7d", Ai, nz);
    printf("Ax = ");
    print_vector("%7.3f", Ax, nz);
    putchar('\n');

    double **b;
    make_matrix(b, m, n);
    sparse_unpack(b, m, n, Ap, Ai, Ax);
    
    double **c;
    make_matrix(c, m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    
    printf("The difference of the original and reconstructed matrices:\n");
    print_matrix("%7.3f ", c, m, n);
    
    return 0;
}