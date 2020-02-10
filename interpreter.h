#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "quantsim.h"

/**
 * Procedure:
 * 1. Count the number of lines
 * 2. Load that many qubits
 * 3. Load that many string pointers, pointing at the start of each line
 */
void interpret(char *in, FILE *out);

void initialize(char *in, long *num_qubits, struct Mat **qubits, char ***line_pointers);

/**
 * Advances *stream to the end of the gate. TODO: maybe copy strol's design
 * and accept a separate pointer to be adjusted to the end of the gate
 * expression (includes parentheses with operands inside)
 *
 * *out is modified to hold the full gate expression.
 */
void read_next_gate_exp(char **stream, char **out);

void load_file(FILE *fp, char **out);

#endif