#ifndef MAT_H
#define MAT_H

struct Mat {
    int rows;
    int cols;
    double *data;
};

void Mat_init(struct Mat *mat, int rows, int cols);
void Mat_init_with_data(struct Mat *mat, int rows, int cols, ...);
double Mat_get(struct Mat *mat, int row, int col);
void Mat_set(struct Mat *mat, int row, int col, double val);
void Mat_dot(struct Mat *mat1, struct Mat *mat2, struct Mat *result);
void Mat_kronecker(struct Mat *mat1, struct Mat *mat2, struct Mat *result);
void Mat_print();

void generate_identity(int size, struct Mat *result);

#endif