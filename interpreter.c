#include "quantsim.h"

void interpret(char *in, FILE *out) {
    long num_qubits;
    struct Mat *qubits;
    char **line_pointers;
    initialize(in, &num_qubits, &qubits, &line_pointers);

    /* Will hold each column's gates as they are encountered */
    char **gates;
    while(1) {
        for(int i = 0; i < num_qubits; i++) {
            char *gate_exp;
            read_next_gate_exp(&(line_pointers[i]), &gate_exp);

            struct Mat gate;
            parse_gate(gate_exp, &gate);

            /* I imagine if it's not in the first 3 bytes, it's not there. */
            if(memchr(gate_exp, '(', 3) != NULL) {
                int *operands;
                parse_operands(gate_exp, &operands);
            }
        }

        /* If any of the lines have no more symbols encountered (whether thats
         * a gate or simply a placeholder _ ), then it can be assumed the
         * program has ended. */
        if(strcmp((gates)[0], "")) { // can this be shortened?
            break;
        }
    }

    // TODO free memory
}

void initialize(char *in, long *num_qubits, struct Mat **qubits, char ***line_pointers) {
    /* First # is # of qubits */
    long num = strtol(in, &in, 10); // I LOVE this function

    *num_qubits    = num;
    *qubits        = malloc(num * sizeof(struct Mat));
    *line_pointers = malloc(num * sizeof(char *));

    int i = 0;
    /* We iterate through the string as opposed to just initializing 5 qubits
     * because we need the line_pointers to point to the start of each line. */
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


// TODO: for this and related functions, there's definitely a more idiomatic
// way to isolate a SUBSTRING.
void read_next_gate_exp(char **stream, char **out) {
    /* Get to the next gate */
    for(;
        !IS_GATE(**stream) && !IS_END(**stream);
        *stream = *stream + 1
    );
    char *start = *stream;

    /* Get to the start of the next gate, or the end of the code. */
    for(;
        !IS_GATE(**stream) && !IS_END(**stream);
        *stream = *stream + 1
    );

    size_t size = (size_t)(*stream - start);
    *out = malloc(size + 1); // +1 for '\0'

    memcpy(*out, start, size);
    (*out)[size] = '\0';
}

void parse_gate(char *gate_exp, struct Mat *gate) {
    char *start = gate_exp;
    for(;
        *gate_exp != '\0' && *gate_exp != '(' && *gate_exp != ' ';
        gate_exp++
    );

    size_t size = (size_t)(gate_exp - start);
    char *gate_str = malloc(size + 1); // +1 for '\0'

    memcpy(gate_str, start, size);
    gate_str[size] = '\0';


}

void parse_operands(char *gate_exp, int **operands) {

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