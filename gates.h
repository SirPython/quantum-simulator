#ifndef GATES_H
#define GATES_H

/**
 * The name field is used for lookup; when interpreting quantsim code, the
 * symbols will be used and will be corresponded to the gate functions here.
 */

 //void Gate_generate_mat(struct Gate *g, int n);

// I don't think this way of organizing gates will work. Some gates need to be
// scalable, such as negation, while other gates like CNOT operate on exactly
// two qubits.

// or maybe write every gate as a 2x2, which is the minimum size. Then, use
// a scalable identity matrix with the kronecker product to change the size
// of the gate

struct Mat pauli_x = {
    2,2,
    (double[4]){
        0, 1,
        1, 0
    }
};

struct {
    char symbol;
    struct Mat mat;
} GateLookup[] = {
    'X', pauli_x
};

#endif