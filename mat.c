#include "mat.h"

#include <stdlib.h>
#include <stdio.h>

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

void Mat_dot(struct Mat *m1, struct Mat *m2, struct Mat *result) {
    if(m1->cols != m2->rows) {
        return;
    }

    Mat_init(result, m1->rows, m2->cols);

    for(int i = 0; i < m1->rows; i++) {
        for(int j = 0; j < m2->cols; j++) {
            double sum = 0;
            for(int k = 0; k < m2->rows; k++) {
                sum += Mat_get(m1, i, k) * Mat_get(m2, k, j);
            }

            Mat_set(result, i, j, sum);
        }
    }
}

void Mat_kronecker(struct Mat *m1, struct Mat *m2, struct Mat *result) {
    Mat_init(result, m1->rows * m2->rows, m1->cols * m2->cols);

    for(int i = 0; i < m1->rows; i++) {
        for(int j = 0; j < m1->cols; j++) {
            for(int k = 0; k < m2->rows; k++) {
                for(int l = 0; l < m2->cols; l++) {
                    // Iw + Jx + Ky + Lz = ?
                    // Iw + (J * m1->cols) + Ky + L
                    Mat_set(
                        result,
                        (i * m1->rows) + k,
                        (j * m1->cols) + l,
                        Mat_get(m1, i, j) * Mat_get(m2, k, l)
                    );
                }
            }
        }
    }
}