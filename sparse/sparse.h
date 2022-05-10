#ifndef H_SPARSE_H
#define H_SPARSE_H

void sparse_pack(double **a, int m, int n, int *Ap, int *Ai, double *Ax);
void sparse_unpack(double **a, int m, int n, int *Ap, int *Ai, double *Ax);

#endif /* H_SPARSE_H */