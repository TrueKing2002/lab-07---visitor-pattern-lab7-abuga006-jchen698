#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "rand.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

//TEST(OpTest, OpStringifyNonZero) {
//    Op* test = new Op(8);
//    EXPECT_EQ(test->stringify(), "8.0");
//}

TEST(OpTest, OpEvaluateRand) {
    Rand* test = new Rand();
    EXPECT_EQ(test->evaluate(), rand() % 100 - 3);
}

#endif //__OP_TEST_HPP__
