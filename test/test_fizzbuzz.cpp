#include "gtest/gtest.h"

extern "C" {
#include "fizzbuzz.h"
}

namespace {

TEST(fizzbuzz_get_answer, 3) {
    ASSERT_STREQ("Fizz", fizzbuzz_get_answer(3));
    ASSERT_STREQ("Fizz", fizzbuzz_get_answer(6));
    ASSERT_STREQ("Fizz", fizzbuzz_get_answer(9));
    ASSERT_STREQ("Fizz", fizzbuzz_get_answer(12));
}

TEST(fizzbuzz_get_answer, 5) {
    ASSERT_STREQ("Buzz", fizzbuzz_get_answer(5));
    ASSERT_STREQ("Buzz", fizzbuzz_get_answer(10));
}

TEST(fizzbuzz_get_answer, 3_and_5) {
    ASSERT_STREQ("FizzBuzz", fizzbuzz_get_answer(15));
    ASSERT_STREQ("FizzBuzz", fizzbuzz_get_answer(30));
}

TEST(fizzbuzz_get_answer, 1_and_2_and_4) {
    ASSERT_STREQ("1", fizzbuzz_get_answer(1));
    ASSERT_STREQ("2", fizzbuzz_get_answer(2));
    ASSERT_STREQ("4", fizzbuzz_get_answer(4));
}

TEST(fizzbuzz_free_answer, 1_and_3_and_5_and_15) {
    // 「free されているか？」のテストは難しいので、
    // 呼び出して落ちなければ OK とする。
    char* one = fizzbuzz_get_answer(1);
    fizzbuzz_free_answer(one);
    char* three = fizzbuzz_get_answer(3);
    fizzbuzz_free_answer(three);
    char* five = fizzbuzz_get_answer(5);
    fizzbuzz_free_answer(five);
    char* fifteen = fizzbuzz_get_answer(15);
    fizzbuzz_free_answer(fifteen);
}

TEST(fizzbuzz_get_answer_array, 15) {
    char** answers = fizzbuzz_get_answer_array(15);
    ASSERT_STREQ("1", answers[0]);
    ASSERT_STREQ("2", answers[1]);
    ASSERT_STREQ("Fizz", answers[2]);
    ASSERT_STREQ("4", answers[3]);
    ASSERT_STREQ("Buzz", answers[4]);
    ASSERT_STREQ("Fizz", answers[5]);
    ASSERT_STREQ("7", answers[6]);
    ASSERT_STREQ("8", answers[7]);
    ASSERT_STREQ("Fizz", answers[8]);
    ASSERT_STREQ("Buzz", answers[9]);
    ASSERT_STREQ("11", answers[10]);
    ASSERT_STREQ("Fizz", answers[11]);
    ASSERT_STREQ("13", answers[12]);
    ASSERT_STREQ("14", answers[13]);
    ASSERT_STREQ("FizzBuzz", answers[14]);
}

}

