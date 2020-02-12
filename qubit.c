#include "quantsim.h"

void Qubit_init(Qubit *qubit) {
    Mat_init(qubit, 2, 1);
    Mat_set(qubit, 0, 0, 1);
}

void Qreg_init(QubitRegister *qreg, int num) {
    *qreg = malloc(sizeof(Qubit) * num);

    for(; num > 0; num--) {
        Qubit qubit;
        Qubit_init(&qubit);
        (*qreg)[num] = qubit;
    }
}

void Qubit_apply(Gate *gate, Qubit *out_qubit, int num_qubits, ...) {

    // IN ARE PASSED THE COMBINED GATES FOR THE COLUMN AS WELL AS THE COMBINED
    // QUBITS FROM THE REGISTER (MAKE A QREG FUNCTION THAT MAKES USE OF THE COMBINE
    // FUNCTION
    // IF IT'S AN UNDERSCORE, IT'S THE IDENTITY UNLESS ANOTHER GATE REFERRED
    // TO IT EXPLICITLY. OR, HOW ABOUT THIS, KNOWING THE SIZE OF EACH GATE,
    // THE NEXT N QUBITS DOWN ARE THE ASSUMED OPERANDS <-- WILL MAKE CODE
    // EASIER TO READ

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

double Qubit_qmeasure(Qubit *qubit) {
    double root_zero_odds = Mat_get(qubit, 0, 0);

    return root_zero_odds * root_zero_odds;
}

bool Qubit_cmeasure(Qubit *qubit) {
    return rand() >= Qubit_qmeasure(qubit);
}