#include "op.hpp"
#include "add.hpp"

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
    
