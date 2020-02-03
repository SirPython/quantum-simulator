#include "qubit.h"

#include <stdbool.h>
#include <stdlib.h>

void Qubit_init(struct Qubit *q, int val) {
    struct Mat m;
    Mat_init(&m, 2, 1);
    Mat_set(&m, val, 0, 1);

    q->m = m;
}

void identity(struct Qubit *c) {
    static struct Mat m = {
        2,2
        1, 0
        0, 1
    };

    struct Qubit *placeholder;
}

void Qubit_apply(struct Qubit *q, struct Gate *g) {
    struct Qubit *placeholder;

    struct Mat *q_mat = &q->m;
    struct Mat *g_mat = &g->m;

    struct Mat result;
    Mat_dot(q_mat, g_mat, &result);

    *q = result;
}

double Qubit_qmeasure(struct Qubit *q) {
    double root_zero_odds = Mat_get(&q->m, 0, 0);

    return root_zero_odds * root_zero_odds;
}

bool Qubit_cmeasure(struct Qubit *q) {
    return rand() >= qmeasure(q);
}