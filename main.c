#include "quantsim.h"

int main(int argc, char **argv) {
    /*srand(time(NULL));

    FILE *in = fopen("./sample/sample.quantsim", "r");
    FILE *out = stdout;

    char *source;
    load_file(in, &source);

    interpret(source, out);*/

    struct Mat a;
    Mat_init_with_data(&a, 2, 1, 1, 0);

    struct Mat b;
    Mat_init_with_data(&a, 2, 1, 0, 1);

    struct Mat c;
    Mat_init_with_data(&a, 2, 1, 1, 0);

    struct Mat d;
    Mat_kronecker(&a, &b, &d);

    struct Mat e;
    Mat_kronecker(&d, &c, &e);

    Mat_print(&a);

    return 0;
}

/**
 * Watch out for memory issues... I feel like there's gonna need to be a lot
 * of garbage collection.
 */