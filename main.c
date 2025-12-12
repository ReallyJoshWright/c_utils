#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "result.h"

ResultInt divide(int a, int b) {
    if (b == 0) {
        return unexpectedInt("Cannot divide by zero");
    }

    return expectedInt(a / b);
}

ResultStr something(char* something) {
    if (strcmp(something, "Harry") == 0) {
        return unexpectedStr("Error");
    }

    return expectedStr("Good");
}

int main(void) {
    ResultInt res = divide(20, 4);
    if (!res.has_value) {
        printf("%s\n", res.error);
        return 1;
    }
    printf("%d\n", res.value);

    ResultStr res2 = something("Harry");
    if (!res2.has_value) {
        printf("%s\n", res2.error);
        return 1;
    }
    printf("%s\n", res2.value);

    return 0;
}
