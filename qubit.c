#include "qubit.h"

#include <stdbool.h>
#include <stdlib.h>

void Qubit_init(struct Mat *qubit, int val) {
    Mat_init(qubit, 2, 1);
    Mat_set(qubit, val, 0, 1);
}

void Qubit_apply(struct Mat *qubit, struct Mat *gate) {
    struct Mat scaled_gate;

    if(qubit->rows > 2) {
        struct Mat identity;
        generate_identity(qubit->rows, &identity);

        Mat_kronecker(gate, &identity, &scaled_gate);
    } else {
        scaled_gate = *gate;
    }

    struct Mat output;
    Mat_dot(qubit, &scaled_gate, &output);

    *qubit = output;
}

double Qubit_qmeasure(struct Mat *qubit) {
    double root_zero_odds = Mat_get(qubit, 0, 0);

    return root_zero_odds * root_zero_odds;
}

bool Qubit_cmeasure(struct Mat *qubit) {
    return rand() >= Qubit_qmeasure(qubit);
}