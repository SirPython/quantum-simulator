#include "qubit.h"

void Qubit_init(struct Qubit *q, int val) {
    struct Mat m;
    Mat_init(&m, 2, 1);
    Mat_set(&m, val, 0, 1);

    q->m = m;
}