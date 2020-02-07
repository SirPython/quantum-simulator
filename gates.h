#ifndef GATES_H
#define GATES_H

#include <complex.h>

#define GATE(name, v1, v2, v3, v4) struct Mat name = { \
    2,2, \
    (double []) { \
        v1, v2, \
        v3, v4 \
    } \
};

GATE(hadamard,
    7071067812, 7071067812,
    7071067812,-7071067812
);

GATE(pauli_x,
    0, 1,
    1, 0
);

GATE(pauli_y,
    0, -I,
    I, 0
);

GATE(pauli_z,
    1, 0,
    0, -1
);

GATE(root_not,
    0.5 * (1 + I), 0.5 * (1 - I),
    0.5 * (1 - I), 0.5 * (1 + I)
);

struct Mat swap = {
    4,4,
    (double[]) {
        1, 0, 0, 0,
        0, 0, 1, 0,
        0, 1, 0, 0,
        0, 0, 0, 1
    }
};

#endif