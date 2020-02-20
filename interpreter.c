#include "quantsim.h"

void interpret(char *in, FILE *out) {
    QubitRegister *qregs;
    char **line_pointers;
    initialize(in, &qregs, &line_pointers);

    while(1) {
        struct Mat combined_register;
        Mat_combine(qregs, &combined_register);

        struct Mat combined_gates;

        int operands_expected = 0;
        for(int i = 0; qregs[i] != NULL; i++) {
            if(operands_expected > 0) {
                operands_expected--;
                continue;
            }

            char *gate_exp;
            read_next_gate_exp(&(line_pointers[i]), &gate_exp);
            struct Mat *gate  = parse_gate(gate_exp);
            operands_expected = (gate->rows / 2) - 1;

            struct Mat new;
            Mat_combine(&combined_gates, gate, &new);
            combined_gates = new;
        }
    }

    // TODO free memory
}

void initialize(char *in, QubitRegister **qregs, char ***line_pointers) {
    /* First # is # of qubits */
    long num_regs = strtol(in, &in, 10); // I LOVE this function

    /* +1 b/c the last element will be null to denote the end */
    *qregs = malloc(sizeof(QubitRegister) * (num_regs+1)); // TODO go through and make sure you doing things like this where you dont' create extra blocks of memroy within funcitons

    int num_lines = 0;
    for(int i = 0; i < num_regs; i++) {
        /* Next # is size of qreg */
        long size = strtol(in, &in, 10);

        QubitRegister qreg;
        Qreg_init(&qreg, size);
        (*qregs)[i] = qreg;

        num_lines += size;
    }
    qregs[num_regs] = NULL;

    *line_pointers = malloc(num_lines * sizeof(char *));

    int i = 0;
    /* We iterate through the string as opposed to just initializing 5 qubits
     * because we need the line_pointers to point to the start of each line. */
    while(*in != '\0') {
        if(*in == '\n') {
            (*line_pointers)[i] = in;
            i++;
        }
        in++;
    }
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