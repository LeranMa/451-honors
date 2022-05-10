#include "sparse.h"

void sparse_pack(double **a, int m, int n, int *Ap, int *Ai, double *Ax)
{
    Ap[0] = 0;
    int nz = 0;

    for (int j = 0; j < n; j++)
    {
        Ap[j + 1] = Ap[j];
        for (int i = 0; i < m; i++)
        {
            if (a[i][j] != 0)
            {
                Ap[j + 1]++;
                Ai[nz] = i;
                Ax[nz] = a[i][j];
                nz++;
            }
        }
    }
}

void sparse_unpack(double **a, int m, int n, int *Ap, int *Ai, double *Ax)
{
    int i, j, k;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            a[i][j] = 0.0;
    for (j = 0; j < n; j++)
        for (k = Ap[j]; k < Ap[j+1]; k++) {
            i = Ai[k];
            a[i][j] = Ax[k];
        }
}