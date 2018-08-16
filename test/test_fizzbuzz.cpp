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

}

