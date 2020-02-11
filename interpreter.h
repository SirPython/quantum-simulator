#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "quantsim.h"

#define IS_GATE(a) (a == '_' || (a >= 'A' && a <= 'Z'))
#define IS_END(a) (a == '\0' || a == '\n')
#define IS_LOWER(a) (a >= 'a' && a <= 'z')
#define IS_NUMBER(a) (a >= '0' && a <= '')

#define SKIP_WHILE(item, condition) for(; condition; item = item + 1);

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

struct Mat *parse_gate(char *gate_exp);
void parse_operands(char *gate_exp, int **operands);

void load_file(FILE *fp, char **out);

#endif