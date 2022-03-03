
#include "op.hpp"
#include "pow.hpp"

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

