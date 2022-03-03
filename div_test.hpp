
#include "op.hpp"
#include "div.hpp"


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

