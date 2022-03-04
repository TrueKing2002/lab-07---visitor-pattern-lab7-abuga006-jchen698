#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "rand.hpp"

TEST(OpTest, NumberChildren) {
    Op* test = new Op(10);
    EXPECT_EQ(test->number_of_children(), 0);
}

TEST(OpTest, NumberChildrenRandom) {
    Rand* test = new Rand();
    EXPECT_EQ(test->number_of_children(), 0);
}

TEST(OpTest, NonexistentChild) {
    Op* test = new Op(10);
    EXPECT_EQ(test->get_child(0), nullptr);
}

#endif //__OP_TEST_HPP__
