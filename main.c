#include "quantsim.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    srand(time(NULL));

    struct Mat identity;
    generate_identity(4, &identity);

    Mat_print(&identity);
}

/**
 * Watch out for memory issues... I feel like there's gonna need to be a lot
 * of garbage collection.
 */