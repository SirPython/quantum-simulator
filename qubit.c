#include "quantsim.h"

void Qubit_init(struct Mat *qubit) {
    Mat_init(qubit, 2, 1);
    Mat_set(qubit, 0, 0, 1);
}

void Qubit_apply(struct Mat *gate, struct Mat *out_qubit, int num_qubits, ...) {
    va_list qubits;
    struct Mat scaled_gate;
    struct Mat combined_qubit = va_arg(qubits, struct Mat);

    /* Combine the operand qubits */
    for(; num_qubits-1 > 0; num_qubits--) {
        struct Mat qubit = va_arg(qubits, struct Mat);
        struct Mat new;
        Mat_kronecker(&combined_qubit, &qubit, &new);

        combined_qubit = new;
    }

// oh do you decide the length of a register beforehand?

    va_end(qubits);

    /* Scale the gate to match the size of the combined operand qubits */
    if(combined_qubit.rows > gate->rows) {
        struct Mat identity;
        generate_identity(combined_qubit.rows, &identity);

        Mat_kronecker(gate, &identity, &scaled_gate);
    } else {
        scaled_gate = *gate;
    }

    struct Mat output;
    Mat_dot(&combined_qubit, &scaled_gate, &output);

    *out_qubit = output;
}

double Qubit_qmeasure(struct Mat *qubit) {
    double root_zero_odds = Mat_get(qubit, 0, 0);

    return root_zero_odds * root_zero_odds;
}

bool Qubit_cmeasure(struct Mat *qubit) {
    return rand() >= Qubit_qmeasure(qubit);
}