#include "quantsim.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv) {
    srand(time(NULL));

    struct Mat neg;
    Mat_init(&neg, 2, 2);
    Mat_set(&neg, 0, 0, 0);
    Mat_set(&neg, 0, 1, 1);
    Mat_set(&neg, 1, 0, 1);
    Mat_set(&neg, 1, 1, 0);

    struct Mat zero;
    Mat_init(&zero, 2, 1);
    Mat_set(&zero, 0, 0, 1);
    Mat_set(&zero, 1, 0, 0);

    struct Mat prod;

    Mat_dot(&neg, &zero, &prod);

    Mat_print(&prod);

    printf("%f\n", sqrt(-1));
}

/**
 * Watch out for memory issues... I feel like there's gonna need to be a lot
 * of garbage collection.
 */