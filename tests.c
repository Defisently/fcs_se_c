#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "calc_operations.c"

bool addition_test(void) {
    int result = 0;
    assert(calculate('+', 100, 57, &result) == true);
    assert(result == 157);
}
bool subtraction_test(void) {
    int result = 0;
    assert(calculate('-', 100, 57, &result) == true);
    assert(result == 43);
}

bool multiplication_test(void) {
    int result = 0;
    assert(calculate('*', 23, 5, &result) == true);
    assert(result == 115);
}

bool division_test(void) {
    int result = 0;
    assert(calculate('/', 23, 0, &result) == false);

}

int testing() {
    addition_test();
    subtraction_test();
    multiplication_test();
    division_test();
    printf("Tests passed.\n");
    return 0;
}