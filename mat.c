#include "mat.h"

#include <stdlib.h>

void Mat_init(struct Mat *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;

    m->e = malloc(sizeof(double) * rows * cols);
}

double Mat_get(struct Mat *m, int row, int col) {
    return m->e[(row * m->cols) + col];
}

void Mat_set(struct Mat *m, int row, int col, double val) {
    m->e[(row * m->cols) + col] = val;
}

void Mat_mult(struct Mat *m1, struct Mat *m2, struct Mat *result) {

}

void Mat_tensor(struct Mat *m1, struct Mat *m2, struct Mat *result) {

}