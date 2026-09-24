#include <stdbool.h>

enum ERROR_CODES {
    DIVISION_BY_ZERO = 0,
    INVALID_OPERATION_INPUT = 0,
    INVALID_NUMBER_INPUT = 0
};
int sum(int number1, int number2) {
    return number1 + number2;
}

int multiply(int number1, int number2) {
    return number1 * number2;
}

int divide(int number1, int number2) {
    return number1 / number2;
}

int subtract (int number1, int number2) {
    return number1 - number2;
}

bool calculate(char operation, int number1, int number2, int *out_result) {
    if (operation == '+') {
        *out_result = sum(number1, number2);
        return true;
    }
    else if (operation == '-') {
        *out_result = subtract(number1, number2);
        return true;
    }
    else if (operation == '*') {
        *out_result = multiply(number1, number2);
        return true;
    }
    else if (operation == '/' && number2 == 0) {
        return DIVISION_BY_ZERO;
    }
    return false;
}
