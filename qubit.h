#ifndef QUBIT_H
#define QUBIT_H

struct Qubit {
    struct Mat m;
};

/**
 * val is either 0 or 1 to denote in which index the 1 will be
 */
void Qubit_init(struct Qubit *q, int val);

/**
 * Gates will not return the result nor store the result elsewhere because
 * gates modify their input qubits; the operation is being done ON the qubit.
 */
void identity(struct Qubit *q);
void negation(struct Qubit *q);
void cnot(struct Qubit *q);
void hadamard(struct Qubit *q);

#endif