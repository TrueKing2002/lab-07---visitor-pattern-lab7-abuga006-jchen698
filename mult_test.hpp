#include "op.hpp"
#include "mult.hpp"

TEST(MultTest, MultEvaluateNonZero) {
    Op* left = new Op(8);
    Base* right = new SevenOpMock();
    Mult* test = new Mult(left, right);
    EXPECT_EQ(test->evaluate(), 60);
}

TEST(MultTest, MultStringifyNonZero) {
    Op* left = new Op(8);
    Base* right = new SevenOpMock();
    Mult* test = new Mult(left, right);
    EXPECT_EQ(test->stringify(), "(8*7.5)");
}

TEST(MultTest, MultEvaluateZero) {
    Op* left = new Op(0);
    Base* right = new SevenOpMock();
    Mult* test = new Mult(left, right);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultStringifyZero) {
    Op* left = new Op(0);
    Base* right = new SevenOpMock();
    Mult* test = new Mult(left, right);
    EXPECT_EQ(test->stringify(), "(0*7.5)");
}

TEST(MultTest, MultEvaluateNegative) {
    Op* left = new Op(-8);
    Base* right = new SevenOpMock();
    Mult* test = new Mult(left, right);
    EXPECT_EQ(test->evaluate(), -60);
}

TEST(MultTest, MultStringifyNegative) {
    Op* left = new Op(-8);
    Base* right = new SevenOpMock();
    Mult* test = new Mult(left, right);
    EXPECT_EQ(test->stringify(), "(-8*7.5)");
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
    EXPECT_EQ(test->get_child(1), left);
}
