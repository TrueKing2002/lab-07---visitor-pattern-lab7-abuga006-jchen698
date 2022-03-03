
#include "op.hpp"
#include "sub.hpp" 

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

