#include "quantsim.h"

#include <stdio.h>

int main(int argc, char **argv) {
    struct Mat mat1;
    Mat_init(&mat1, 2, 3);
    Mat_set(&mat1, 0, 0, 1);
    Mat_set(&mat1, 0, 1, 2);
    Mat_set(&mat1, 0, 2, 3);
    Mat_set(&mat1, 1, 0, 4);
    Mat_set(&mat1, 1, 1, 5);
    Mat_set(&mat1, 1, 2, 6);

    struct Mat mat2;
    Mat_init(&mat2, 3, 2);
    Mat_set(&mat2, 0, 0, 7);
    Mat_set(&mat2, 0, 1, 8);
    Mat_set(&mat2, 1, 0, 9);
    Mat_set(&mat2, 1, 1, 10);
    Mat_set(&mat2, 2, 0, 11);
    Mat_set(&mat2, 2, 1, 12);

    struct Mat product;
    Mat_kronecker(&mat1, &mat2, &product);

    for(int i = 0; i < product.rows; i++) {
        for(int j = 0; j < product.cols; j++) {
            printf("(%d, %d) = %f\n", i, j, Mat_get(&product, i, j));
        }
    }
}