#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>

/**
 * Procedure:
 * 1. Count the number of lines
 * 2. Load that many qubits
 * 3. Load that many string pointers, pointing at the start of each line
 */
void interpret(char *in, FILE *out);

void load_file(FILE *fp, char **out);

#endif