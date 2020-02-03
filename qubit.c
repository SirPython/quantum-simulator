#include "qubit.h"

#include <stdbool.h>
#incluce <stdlib.h>

void Qubit_init(struct Qubit *q, int val) {
    struct Mat m;
    Mat_init(&m, 2, 1);
    Mat_set(&m, val, 0, 1);

    q->m = m;
}

double qmeasure(struct Qubit *q) {
    double root_zero_odds = Mat_get(q.m, 0, 0);

    return root_zero_odds * root_zero_odds;
}

bool cmeasure(struct Qubit *q) {
    return rand() >= qmeasure(q);
}