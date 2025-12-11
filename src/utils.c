#include "utils.h"

typedef struct Result {
    int _valueInt;
    char* _error;
    bool _has_value;
    bool (*hasValue)(void);
    int (*value)(void);
    char* (*error)(void);
    void (*setValue)(int);
    void (*setError)(char*);
} Result;

bool result_hasValue(void) {
}

int result_valueInt(void) {
}

char* result_error(void) {
}

void result_setValueInt(int value) {
}

void result_setError() {
}

typedef struct Util {
} Util;
