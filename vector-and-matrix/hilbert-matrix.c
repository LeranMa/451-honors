#include "array.h"
#include <stdio.h>

double **hilbert_matrix(int n)
{
    double **H;
    make_matrix(H, n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            H[i][j] = 1.0 / (1 + i + j);
    return H;
}

int main(void)
{
    double **H;
    int n = 8;
    H = hilbert_matrix(n);
    print_matrix("%7.3f ", H, n, n);
    free_matrix(H);

    double ***C;
    double ****D;
    make_3array(C, 3, 5, 10);
    make_4array(D, 3, 3, 3, 3);
    C[0][0][0] = 1;
    D[0][0][0][0] = 1;
    free_3array(C);
    free_4array(D);
    return 0;
}