#ifndef RESULT_H
#define RESULT_H

typedef struct ResultInt {
    bool has_value;
    int value;
    char* error;
} ResultInt;

typedef struct ResultStr {
    bool has_value;
    char* value;
    char* error;
} ResultStr;

ResultInt unexpectedInt(char* error);
ResultInt expectedInt(int value);

ResultStr unexpectedStr(char* error);
ResultStr expectedStr(char* value);

#endif // RESULT_H
