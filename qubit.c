#include "qubit.h"

#include <stdbool.h>
#include <stdlib.h>

void Qubit_init(struct Qubit *q, int val) {
    struct Mat mat;
    Mat_init(&mat, 2, 1);
    Mat_set(&mat, val, 0, 1);

    q->mat = mat;
}

void Qubit_apply(struct Qubit *q, struct Gate *g) {
    struct Qubit *placeholder;

    struct Mat result;
    Mat_dot(&q->mat, &g->mat, &result);

    placeholder->mat = result;

    *q = placeholder;
}

double Qubit_qmeasure(struct Qubit *q) {
    double root_zero_odds = Mat_get(&q->mat, 0, 0);

    return root_zero_odds * root_zero_odds;
}

bool Qubit_cmeasure(struct Qubit *q) {
    return rand() >= qmeasure(q);
}