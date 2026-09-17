#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "calc_operations.h"

void addition_test(void) {
    int result = 0;
    assert(calculate('+', 100, 57, &result) == true);
    assert(result == 157);
}
void subtraction_test(void) {
    int result = 0;
    assert(calculate('-', 100, 57, &result) == true);
    assert(result == 43);
}

void multiplication_test(void) {
    int result = 0;
    assert(calculate('*', 23, 5, &result) == true);
    assert(result == 115);
}

void division_test(void) {
    int result = 0;
    assert(calculate('/', 23, 0, &result) == false);

}

int main() {
    addition_test();
    subtraction_test();
    multiplication_test();
    division_test();
    printf("Tests passed.\n");
    return 0;
}