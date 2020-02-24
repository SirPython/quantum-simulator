#include "quantsim.h"

void interpret(char *in, FILE *out) {
    Qubit *qubits;
    char **line_pointers;
    initialize(in, &qubits, &line_pointers);

    while(1) {
        struct Mat combined_qubits;
        Mat_combine(&qubits, &combined_qubits);

        struct Mat combined_gates;

        int operands_expected = 0;
        /* rows = 0 signifies ARRAY_END matrix */
        for(int i = 0; qubits[i].rows != 0; i++) {
            if(operands_expected > 0) {
                operands_expected--;
                continue;
            }

            char *gate_exp;
            read_next_gate_exp(&(line_pointers[i]), &gate_exp);
            struct Mat *gate  = parse_gate(gate_exp);
            operands_expected = (gate->rows / 2) - 1;

            struct Mat new;
            Mat_combine((struct Mat *[]) {&combined_gates, gate}, &new);
            combined_gates = new;
        }
    }
    // TODO free memory
}

void initialize(char *in, Qubit **qubits, char ***line_pointers) {
    /* First # is # of qubits */
    long num_qubits = strtol(in, &in, 10); // I LOVE this function

    *qubits        = malloc((num_qubits + 1) * sizeof(Qubit));
    *line_pointers = malloc(num_qubits * sizeof(char *));

    int i = 0;
    /* We iterate through the string as opposed to just initializing 5 qubits
     * because we need the line_pointers to point to the start of each line. */
    while(*in != '\0') {
        if(*in == '\n') {
            struct Mat qubit;
            Qubit_init(&qubit);
            (*qubits)[i] = qubit;

            (*line_pointers)[i] = in;

            i++;
        }
        in++;
    }

    extern struct Mat ARRAY_END;
    (*qubits)[num_qubits] = ARRAY_END;
}


// TODO: for this and related functions, there's definitely a more idiomatic
// way to isolate a SUBSTRING.
void read_next_gate_exp(char **stream, char **out) {
    SKIP_WHILE(*stream, !IS_GATE(**stream) && !IS_END(**stream))
    char *start = *stream;
    SKIP_WHILE(*stream, !IS_GATE(**stream) && !IS_END(**stream))

    size_t size = (size_t)(*stream - start);
    *out = malloc(size + 1); // +1 for '\0'

    memcpy(*out, start, size);
    (*out)[size] = '\0';
}

struct Mat *parse_gate(char *gate_exp) {
    /* All gates will either be a single capital letter of a capital followed
     * by a lowercase letter. */

     char *gate_str = malloc(3);

     /* Capital followed by lowercase */
     if(IS_LOWER(gate_exp[1])) {
         gate_str[0] = gate_exp[0];
         gate_str[1] = gate_exp[1];
         gate_str[2] = '\0';
     }
     /* A single capital letter  */
     else {
         gate_str[0] = gate_exp[0];
         gate_str[1] = '\0';
     }

     return gate_lookup(gate_str);
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