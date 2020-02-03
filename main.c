#include "quantsim.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    srand(time(NULL));

    struct Mat mat1;
    Mat_init(&mat1, 2, 3);
    Mat_set(&mat1, 0, 0, 1);
    Mat_set(&mat1, 0, 1, -4);
    Mat_set(&mat1, 0, 2, 7);
    Mat_set(&mat1, 1, 0, -2);
    Mat_set(&mat1, 1, 1, 3);
    Mat_set(&mat1, 1, 2, 3);

    struct Mat mat2;
    Mat_init(&mat2, 4, 4);
    Mat_set(&mat2, 0, 0, 8);
    Mat_set(&mat2, 0, 1, -9);
    Mat_set(&mat2, 0, 2, -6);
    Mat_set(&mat2, 0, 3, 5);
    Mat_set(&mat2, 1, 0, 1);
    Mat_set(&mat2, 1, 1, -3);
    Mat_set(&mat2, 1, 2, -4);
    Mat_set(&mat2, 1, 3, 7);
    Mat_set(&mat2, 2, 0, 2);
    Mat_set(&mat2, 2, 1, 8);
    Mat_set(&mat2, 2, 2, -8);
    Mat_set(&mat2, 2, 3, -3);
    Mat_set(&mat2, 3, 0, 1);
    Mat_set(&mat2, 3, 1, 2);
    Mat_set(&mat2, 3, 2, -5);
    Mat_set(&mat2, 3, 3, -1);

    struct Mat product;
    Mat_kronecker(&mat1, &mat2, &product);

    for(int i = 0; i < product.rows; i++) {
        for(int j = 0; j < product.cols; j++) {
            printf("(%d, %d) = %f\n", i, j, Mat_get(&product, i, j));
        }
    }
}