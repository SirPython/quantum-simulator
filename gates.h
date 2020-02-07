#ifndef GATES_H
#define GATES_H

#include <complex.h>

#define UNARY_GATE(name,v1,v2,v3,v4) \
    struct Mat name = { \
        2,2, \
        (double []) { \
            v1, v2, \
            v3, v4 \
        } \
    };

#define BINARY_GATE(name,v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15,v16) \
    struct Mat name = { \
        4,4, \
        (double []) { \
            v1,v2,v3,v4, \
            v5,v6,v7,v8, \
            v9,v10,v11,v12, \
            v13,v14,v15,v16 \
        } \
    };

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
)

#endif