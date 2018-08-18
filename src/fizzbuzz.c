#include "fizzbuzz.h"
#include <stdio.h>
#include <stdlib.h>

// fizzbuzz_number_t が unsigned char なので、
// 最大 3 桁 + '\0' で 4 に設定。
#define MAX_DIGIT 4

fizzbuzz_answer_t fizzbuzz_get_answer(fizzbuzz_number_t number) {
    if (number % 15 == 0) {
        return "FizzBuzz";
    }

    if (number % 3 == 0) {
        return "Fizz";
    }

    if (number % 5 == 0) {
        return "Buzz";
    }

    fizzbuzz_answer_t buf = malloc(sizeof(char) * MAX_DIGIT);
    snprintf(buf, MAX_DIGIT, "%d", number);
    return buf;
}

void fizzbuzz_free_answer(fizzbuzz_answer_t answer) {
    // Fizz, Buzz, FizzBuzz であれば、
    // それは定数なので何もしない
    if (answer == "Fizz" || answer == "Buzz" || answer == "FizzBuzz") {
        return;
    }

    // 定数でなければ malloc で確保したものなので free
    free(answer);
}

fizzbuzz_answer_t* fizzbuzz_get_answer_array(fizzbuzz_number_t number) {
    fizzbuzz_answer_t* answers = malloc(sizeof(fizzbuzz_answer_t) * number);
    for (int n = 1; n <= number; n++) {
        int i = n - 1;
        answers[i] = fizzbuzz_get_answer(n);
    }
    return answers;
}

