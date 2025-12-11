#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// #include "utils.h"

#define expected(x) _Generic((x), int: resultInt, char*: resultStr)(x)

typedef enum ResultType {
    Value,
    Error,
} ResultType;

typedef union ResultUnion {
    int i;
    char str[4096];
} ResultUnion;

typedef struct Result {
    ResultType type;
    ResultUnion value;
    bool hasValue;
} Result;

Result resultInt(int value) {
    Result result;
    result.type = Value;
    result.value.i = value;
    result.hasValue = true;
    return result;
}

Result resultStr(char* value) {
    Result result;
    result.type = Value;
    strcpy(result.value.str, value);
    result.hasValue = true;
    return result;
}

Result unexpected(char* error) {
    Result result;
    result.type = Error;
    strcpy(result.value.str, error);
    result.hasValue = false;
    return result;
}

bool hasValue(Result result) {
    return result.hasValue;
}

char* error(Result result) {
    return result.value.str;
}

Result divide(int a, int b) {
    if (b == 0) {
        return unexpected("Cannot divide by zero");
    }
    return expected(a / b);
}

int main(void) {
    Result res = divide(20, 4);
    if (!hasValue(res)) {
        printf("%s\n", res.value.str);
        return 1;
    }
    printf("%d\n", res.value.i);

    return 0;
}
