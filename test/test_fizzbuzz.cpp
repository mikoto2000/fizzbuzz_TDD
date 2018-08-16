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

}

