#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "calc_operations.h"


bool check(char input[50]) {
    int num1 = 0;
    int num2 = 0;
    int res = 0;
    int curr = 0;
    bool has_digit = false;
    bool first_number = false;
    char operation = '\0';
    for (int i = 0; i < 50 && input[i] != '\0'; i++) {
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
        }
    }
    if (has_digit == true && first_number == true) {
        num2 = curr;
    }
    return calculate(operation, num1, num2, &res);
}

int tests(void) {
    int number1, number2 = 0;
    int ans = 0;
    char operation = '\0';
    char buffer[50];
    FILE *fp = fopen("tests.txt", "r");
    if (fp) {
        while (fgets(buffer, 50, fp) != NULL) {
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