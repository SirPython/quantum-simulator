#ifndef GATES_H
#define GATES_H

/**
 * The name field is used for lookup; when interpreting quantsim code, the
 * symbols will be used and will be corresponded to the gate functions here.
 */
static struct Gate {
    char symbol;
    struct Mat m;
};

static struct Gate identity = {
    "I",
    {
        2,2,

        1, 0,
        0, 1
    }
};

static struct Gate negation = {
    "N",
    {
        2,2,

        0, 1,
        1, 0
    }
}

extern struct Gate Gates[] = {
    identity,
    negation
};

#endif