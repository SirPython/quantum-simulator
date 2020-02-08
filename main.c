#include "quantsim.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    srand(time(NULL));

    FILE *in = fopen("./sample/sample.quantsim", "r");
    FILE *out = stdout;

    interpret(in, out);

    return 0;
}

/**
 * Watch out for memory issues... I feel like there's gonna need to be a lot
 * of garbage collection.
 */