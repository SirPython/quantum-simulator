#ifndef GATES_H
#define GATES_H

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
        0.7071067812, 0.7071067812,
        0.7071067812, -0.7071067812
    }
};

#endif