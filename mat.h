#ifndef MAT_H
#define MAT_H

struct Mat {
    int rows;
    int cols;
    double *e;
};

void Mat_init(struct Mat *m, int rows, int cols);
double Mat_get(struct Mat *m, int row, int col);
void Mat_set(struct Mat *m, int row, int col, double val);
void Mat_mult(struct Mat *m1, struct Mat *m2, struct Mat *result);
void Mat_tensor(struct Mat *m1, struct Mat *m2, struct Mat *result);

#endif