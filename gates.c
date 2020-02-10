#include "quantsim.h"

UNARY_GATE(hadamard,
    7071067812, 7071067812,
    7071067812,-7071067812
);

UNARY_GATE(pauli_x,
    0, 1,
    1, 0
);

BINARY_GATE(c_pauli_x,
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 1,
    0, 0, 1, 0
);

UNARY_GATE(pauli_y,
    0, -I,
    I, 0
);

BINARY_GATE(c_pauli_y,
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, -I,
    0, 0, I, 0
);

UNARY_GATE(pauli_z,
    1, 0,
    0, -1
);

BINARY_GATE(c_pauli_z,
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, -1
);

UNARY_GATE(root_not,
    0.5 * (1 + I), 0.5 * (1 - I),
    0.5 * (1 - I), 0.5 * (1 + I)
);

BINARY_GATE(swap,
    1, 0, 0, 0,
    0, 0, 1, 0,
    0, 1, 0, 0,
    0, 0, 0, 1
);

struct Mat *gate_lookup(char *gate_str) {
    static struct item {
        char *name;
        struct Mat *mat;
    } table[] = {
        "H", &hadamard,
        "X", &pauli_x,
        "Cx", &c_pauli_x,
        "Y", &pauli_y,
        "Cy", &c_pauli_y,
        "Z", &pauli_z,
        "Cz", &c_pauli_z,

        NULL, NULL
    };

    for(struct item *i = table; i->name != NULL; i++) {
        if(strcmp(i->name, gate_str) == 0) {
            return i->mat;
        }
    }

    return NULL;
}