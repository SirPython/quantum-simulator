#include "qubit.h"

#include <stdbool.h>
#include <stdlib.h>

void Qubit_init(struct Mat *qubit, int val) {
    Mat_init(qubit, 2, 1);
    Mat_set(qubit, val, 0, 1);
}

void Qubit_apply(struct Mat *qubit, struct Mat *gate) {
    /*struct Qubit placeholder;

    struct Mat result;
    Mat_dot(&q->mat, &g->mat, &result);

    placeholder.mat = result;

    *q = placeholder;*/

    // needs to scale size of gate with identity matrix
}

double Qubit_qmeasure(struct Mat *qubit) {
    double root_zero_odds = Mat_get(qubit, 0, 0);

    return root_zero_odds * root_zero_odds;
}

bool Qubit_cmeasure(struct Mat *qubit) {
    return rand() >= Qubit_qmeasure(qubit);
}