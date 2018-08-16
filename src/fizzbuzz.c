#include "fizzbuzz.h"

char* fizzbuzz_get_answer(fizzbuzz_number_t number) {
    if (number % 3 == 0) {
        return "Fizz";
    }

    if (number % 5 == 0) {
        return "Buzz";
    }

    return "";
}

