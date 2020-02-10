#include "quantsim.h"

void interpret(char *in, FILE *out) {
    struct Mat *qubits;
    char **line_pointers;
    initialize(in, &qubits, &line_pointers);

    
}

void initialize(char *in, struct Mat **qubits, char ***line_pointers) {
    /* First # is # of qubits */
    long num_qubits = strtol(in, &in, 10); // I LOVE this function
    *qubits        = malloc(num_qubits * sizeof(struct Mat));
    *line_pointers = malloc(num_qubits * sizeof(char *));

    int i = 0;
    while(*in != '\0') {
        if(*in == '\n') {
            struct Mat qubit;
            Qubit_init(&qubit);
            *qubits[i] = qubit;

            *line_pointers[i] = in;

            i++;
        }
        in++;
    }
}

void read_next_gate(char **stream, char **out) {
    for(; **stream == ' '; *stream = *stream + 1);
    char *start = *stream;
    for(; **stream != ' '; *stream = *stream + 1); // this doesn't allow spaces in gate operands.. maybe change
    char *end = *stream;

    size_t size = (size_t)(end - start);
    *out = malloc(size + 1); // +1 for '\0'

    memcpy(*out, *start, size);
    (*out)[size] = '\0';
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