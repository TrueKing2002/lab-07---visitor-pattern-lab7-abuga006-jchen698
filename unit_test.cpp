#include "gtest/gtest.h"

#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

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

TEST(AddTest, NumberChildren) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Add* test = new Add(left, right);
    EXPECT_EQ(test->number_of_children(), 2);
}

TEST(AddTest, ChildLeft) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Add* test = new Add(left, right);
    EXPECT_EQ(test->get_child(0), left);
}

TEST(AddTest, ChildRight) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Add* test = new Add(left, right);
    EXPECT_EQ(test->get_child(1), right);
}

TEST(SubTest, NumberChildren) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Sub* test = new Sub(left, right);
    EXPECT_EQ(test->number_of_children(), 2);
}

TEST(SubTest, ChildLeft) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Sub* test = new Sub(left, right);
    EXPECT_EQ(test->get_child(0), left);
}

TEST(SubTest, ChildRight) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Sub* test = new Sub(left, right);
    EXPECT_EQ(test->get_child(1), right);
}

TEST(MultTest, NumberChildren) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Mult* test = new Mult(left, right);
    EXPECT_EQ(test->number_of_children(), 2);
}

TEST(MultTest, ChildLeft) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Mult* test = new Mult(left, right);
    EXPECT_EQ(test->get_child(0), left);
}

TEST(MultTest, ChildRight) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Mult* test = new Mult(left, right);
    EXPECT_EQ(test->get_child(1), right);
}

TEST(DivTest, NumberChildren) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Div* test = new Div(left, right);
    EXPECT_EQ(test->number_of_children(), 2);
}

TEST(DivTest, ChildLeft) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Div* test = new Div(left, right);
    EXPECT_EQ(test->get_child(0), left);
}

TEST(DivTest, ChildRight) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Div* test = new Div(left, right);
    EXPECT_EQ(test->get_child(1), right);
}

TEST(PowTest, NumberChildren) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Pow* test = new Pow(left, right);
    EXPECT_EQ(test->number_of_children(), 2);
}

TEST(PowTest, ChildLeft) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Pow* test = new Pow(left, right);
    EXPECT_EQ(test->get_child(0), left);
}

TEST(PowTest, ChildRight) {
    Op* left = new Op(10);
    Base* right = new Op(20);
    Pow* test = new Pow(left, right);
    EXPECT_EQ(test->get_child(1), right);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
