#include "quantsim.h"

int main(int argc, char **argv) {
    srand(time(NULL));

    FILE *in = fopen("./sample/sample.quantsim", "r");
    FILE *out = stdout;

    char *source;
    load_file(in, &source);

    interpret(source, out);

    return 0;
}

/**
 * Watch out for memory issues... I feel like there's gonna need to be a lot
 * of garbage collection.
 */