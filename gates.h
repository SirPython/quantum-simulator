#ifndef GATES_H
#define GATES_H

#include "quantsim.h"

// the frequent linker errors I get from this tell me this is a very wrong
// way to do this.

typedef struct Mat Gate;

#define UNARY_GATE(name,v1,v2,v3,v4) \
    Gate name = { \
        2,2, \
        (double []) { \
            v1, v2, \
            v3, v4 \
        } \
    };

#define BINARY_GATE(name,v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15,v16) \
    Gate name = { \
        4,4, \
        (double []) { \
            v1,v2,v3,v4, \
            v5,v6,v7,v8, \
            v9,v10,v11,v12, \
            v13,v14,v15,v16 \
        } \
    };

Gate *gate_lookup(char *gate_str);

#endif