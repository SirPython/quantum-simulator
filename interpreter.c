#include "quantsim.h"

void interpret(char *in, FILE *out) {
    int num_qubits;
    struct Mat *qubits;
    char **line_pointers;
    initialize(in, &num_qubits, &qubits, &line_pointers);

    /* Will hold each column's gates as they are encountered */
    char **gates;
    while(1) {
        for(i = 0; i < num_qubits; i++) {
            char *gate;
            read_next_gate_exp((*line_pointers)[i], &gate);

            // Now the gate exp needs to be split into the gate itself
            // and the operands it acts upon (if any)
            // the operands can be delivered in a list of ints.

            //int operands[];
            //get_operands(gate, &operands;
            //for(# of operands) qubits[operands[i]]
        }

        /* If any of the lines have no more symbols encountered (whether thats
         * a gate or simply a placeholder _ ), then it can be assumed the
         * program has ended. */
        if(strcmp((*gates)[0], "")) { // can this be shortened?
            break;
        }
    }

    // TODO free memory
}

void initialize(char *in, struct Mat **qubits, char ***line_pointers) {
    /* First # is # of qubits */
    long num_qubits = strtol(in, &in, 10); // I LOVE this function
    *qubits        = malloc(num_qubits * sizeof(struct Mat));
    *line_pointers = malloc(num_qubits * sizeof(char *));

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

void read_next_gate_exp(char **stream, char **out) {
    /* Skips past the spaces */
    for(;
        **stream == ' ' && **stream != '\0' && **stream != '\n';
        *stream = *stream + 1
    );
    char *start = *stream;

    /* Skips UNTIL there are spaces */
    for(;
        **stream != ' ' && **stream != '\0' && **stream != '\n';
        *stream = *stream + 1
    ); // this doesn't allow spaces in gate operands.. maybe change
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