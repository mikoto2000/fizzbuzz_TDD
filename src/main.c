#include <stdio.h>
#include <stdlib.h>

#include "fizzbuzz.h"

/**
 * main.c
 *
 * 第一引数で指定した数までの FizzBuzz の回答を、スペース区切りで表示する。
 * (異常系はゆるして...)
 *
 */
int main(int argc, char* argv[]) {
    if (argc != 2) {
        // 想定通りの引数が渡されていなければ異常終了
        exit(1);
    }

    fizzbuzz_number_t number = atoi(argv[1]);
    fizzbuzz_answer_t* fizzbuzz_answers = fizzbuzz_get_answer_array(number);

    int last_index = number -1;
    for (int i = 1; i < last_index; i++) {
        printf(" %s", fizzbuzz_answers[i]);
    }

    // 最後の要素は末尾にスペースを付けちゃだめなのでループの外で printf する
    printf("%s", fizzbuzz_answers[last_index]);

    fizzbuzz_free_answer_array(number, fizzbuzz_answers);

    return 0;
}

