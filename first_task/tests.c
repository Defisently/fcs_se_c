#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "calc_operations.h"


bool check_equal(int num1, int num2) {
    const double EPSILON = 1e-6;
    if (abs(num1 - num2) < EPSILON) {
        return true;
    } else {
        return false;
    }
}

bool check(char input[60]) {
    int num1 = 0;
    int num2 = 0;
    int res = 0;
    int curr = 0;
    int true_result = 0;
    bool has_digit = false;
    bool first_number = false;
    bool second_number = false;
    char operation = '\0';
    for (int i = 0; i < 60 && input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            continue;
        } else if (strchr("+-*/", input[i]) != NULL) {
            operation = input[i];
            if (has_digit && first_number == false) {
                num1 = curr;
                curr = 0;
                has_digit = false;
                first_number = true;
            }
        } else if (input[i] >= '0' && input[i] <= '9') {
            curr = curr * 10 + (input[i] - '0');
            has_digit = true;
        } else if (input[i] == '=') {
            if (first_number == true && has_digit == true && second_number == false) {
                num2 = curr;
                curr = 0;
                second_number = true;
            }
        }
    }
    if (has_digit == true && first_number == true && second_number == true) {
        true_result = curr;
    }
    bool calc_ok = calculate(operation, num1, num2, &res);
    if (check_equal(true_result, res) && calc_ok == true) {
        return true;
    } else {
        return false;
    }
}

int tests(void) {
    int number1, number2 = 0;
    int ans = 0;
    char operation = '\0';
    char buffer[60];
    FILE *fp = fopen("tests.txt", "r");
    if (fp) {
        while (fgets(buffer, 60, fp) != NULL) {
            if (check(buffer)) {
                printf("%s", "Test passed!\n");
            } else {
                printf("%s", "Something went wrong!\n");
            }
        }
    }
    return 0;
}

int main() {
    tests();
    return 0;
}