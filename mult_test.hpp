
#include "op.hpp"
#include "mult.hpp"


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
    EXPECT_EQ(test->get_child(1), left);
}

