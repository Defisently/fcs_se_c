#ifndef CALC_OPERATIONS_H
#define CALC_OPERATIONS_H

int sum(int number1, int number2);
int subtract(int number1, int number2);
int multiply(int number1, int number2);
int divide(int number1, int number2);
int calculate(char operation, int number1, int number2, int *out_result);

#endif