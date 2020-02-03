#ifndef QUBIT_H
#define QUBIT_H

#include "mat.h"

#include <stdbool.h>

struct Qubit {
    struct Mat m;
};

/**
 * val is either 0 or 1 to denote in which index the 1 will be
 */
void Qubit_init(struct Qubit *q, int val);

/**
 * Apply a gate to a qubit.
 *
 * The qubit itself IS modified because that's how quantum operations work.
 */
void Qubit_apply(struct Qubit *q, struct Gate *g);

/**
 * Quantum measurement: returns the likelihood of a collapse to zero
 */
double Qubit_qmeasure(struct Qubit *q);

/**
 * Classical measurement: collapses the qubit
 */
bool Qubit_cmeasure(struct Qubit *q);

#endif