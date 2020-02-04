#include "mat.h"

#include <stdlib.h>
#include <stdio.h>

void Mat_init(struct Mat *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;

    mat->data = malloc(sizeof(double) * rows * cols);
}

double Mat_get(struct Mat *mat, int row, int col) {
    return mat->data[(row * mat->cols) + col];
}

void Mat_set(struct Mat *mat, int row, int col, double val) {
    mat->data[(row * mat->cols) + col] = val;
}

void Mat_dot(struct Mat *mat1, struct Mat *mat2, struct Mat *result) {
    if(mat1->cols != mat2->rows) {
        return;
    }

    Mat_init(result, mat1->rows, mat2->cols);

    for(int i = 0; i < mat1->rows; i++) {
        for(int j = 0; j < mat2->cols; j++) {
            double sum = 0;
            for(int k = 0; k < mat2->rows; k++) {
                sum += Mat_get(mat1, i, k) * Mat_get(mat2, k, j);
            }

            Mat_set(result, i, j, sum);
        }
    }
}

void Mat_kronecker(struct Mat *mat1, struct Mat *mat2, struct Mat *result) {
    Mat_init(result, mat1->rows * mat2->rows, mat1->cols * mat2->cols);

    for(int i = 0; i < mat1->rows; i++) {
        for(int j = 0; j < mat1->cols; j++) {
            for(int k = 0; k < mat2->rows; k++) {
                for(int l = 0; l < mat2->cols; l++) {
                    Mat_set(
                        result,
                        (i * mat2->rows) + k,
                        (j * mat2->cols) + l,
                        Mat_get(mat1, i, j) * Mat_get(mat2, k, l)
                    );
                }
            }
        }
    }
}

void Mat_print(struct Mat *mat) {
    for(int i = 0; i < mat->rows; i++) {
        for(int j = 0; j < mat->cols; j++) {
            printf("(%d, %d) = %f\n", i, j, Mat_get(mat, i, j));
        }
    }
}