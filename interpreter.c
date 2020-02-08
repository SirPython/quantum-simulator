#include "interpreter.h"

#include <stdio.h>
#include <stdlib.h>

void interpret(char *in, FILE *out) {
    /* First number is # of qubits */
    long num_qubits = strtol(in, in, 10);
    struct Mat    qubits[num_qubits];
    char **line_pointers[num_qubits];

    int i = 0;
    while(*in != '\0') {
        if(*in == '\n') {
            struct Mat qubit;
            Qubit_init(&qubit);
            qubits[i] = qubit;

            line_pointers[i] = in;

            i++;
        }
        in++;
    }
}

void load_file(FILE *fp, char **out) {
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *content = malloc(size + 1); // for null terminator
    char *start = content;

    char c;
    while((c = getc(fp)) != EOF) {
        *content = c;

        content++;
    }

    *content = '\0';

    *out = start;
}