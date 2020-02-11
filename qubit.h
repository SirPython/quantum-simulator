#ifndef QUBIT_H
#define QUBIT_H

#include "quantsim.h"

/**
 * A qubit (? or qubit register?) is just a vector.
 */

/**
 * Initializes to a 0 state
 */
void Qubit_init(struct Mat *qubit);

/**
 * Apply a gate to a qubit/qubit register?
 *
 * The qubit itself IS modified because that's how quantum operations work.
 */


void Qubit_apply(struct Mat *gate, struct Mat *out_qubit, int num_qubits, ...);
 /**
 * Quantum measurement: returns the likelihood of a collapse to zero
 */
double Qubit_qmeasure(struct Mat *qubit);

/**
 * Classical measurement: collapses the qubit
 */
bool Qubit_cmeasure(struct Mat *qubit);

#endif