#ifndef GATES_H
#define GATES_H

#include <math.h>

struct Mat pauli_x = {
    2,2,
    (double[]){
        0, 1,
        1, 0
    }
};

struct Mat hadamard = {
    2,2,
    (double []) {
        sqrt(1/2), sqrt(1/2),
        sqrt(1/2), -sqrt(1/2)
    }
};

#endif