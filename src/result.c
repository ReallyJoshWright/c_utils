#include "result.h"

ResultInt unexpectedInt(char* error) {
    ResultInt result;
    result.value = 0;
    result.error = error;
    result.has_value = false;
    return result;
}

ResultInt expectedInt(int value) {
    ResultInt result;
    result.value = value;
    result.error = "";
    result.has_value = true;
    return result;
}

ResultStr unexpectedStr(char* error) {
    ResultStr result;
    result.value = 0;
    result.error = error;
    result.has_value = false;
    return result;
}

ResultStr expectedStr(char* value) {
    ResultStr result;
    result.value = value;
    result.error = "";
    result.has_value = true;
    return result;
}
