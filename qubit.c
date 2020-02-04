#include "qubit.h"

#include <stdbool.h>
#include <stdlib.h>

void Qubit_init(struct Mat *mat, int val) {
    Mat_init(mat, 2, 1);
    Mat_set(&mat, val, 0, 1);
}

void Qubit_apply(struct Qubit *q, struct Mat *gate) {
    /*struct Qubit placeholder;

    struct Mat result;
    Mat_dot(&q->mat, &g->mat, &result);

    placeholder.mat = result;

    *q = placeholder;*/

    // needs to scale size of gate with identity matrix
}

double Qubit_qmeasure(struct Mat *mat) {
    double root_zero_odds = Mat_get(mat, 0, 0);

    return root_zero_odds * root_zero_odds;
}

bool Qubit_cmeasure(struct Mat *mat) {
    return rand() >= Qubit_qmeasure(mat);
}