#include "op.hpp"
#include "add.hpp"

TEST(AddTest, AddEvaluateNormal) {
    Op* left = new Op(10);
    Base* right = new SevenOpMock();
    Add* test = new Add(left, right);
    EXPECT_EQ(test->evaluate(), 17.5);
}

TEST(AddTest, AddStringifyNormal) {
    Op* left = new Op(10);
    Base* right = new SevenOpMock();
    Add* test = new Add(left, right);
    EXPECT_EQ(test->stringify(), "(10+7.5)");
}

TEST(AddTest, AddEvaluateZero) {
    Op* left = new Op(0);
    Base* right = new SevenOpMock();
    Add* test = new Add(left, right);
    EXPECT_EQ(test->evaluate(), 7.5);
}

TEST(AddTest, AddStringifyZero) {
    Op* left = new Op(0);
    Base* right = new SevenOpMock();
    Add* test = new Add(left, right);
    EXPECT_EQ(test->stringify(), "(0+7.5)");
}

TEST(AddTest, AddEvaluateNeg) {
    Op* left = new Op(-10);
    Base* right = new SevenOpMock();
    Add* test = new Add(left, right);
    EXPECT_EQ(test->evaluate(), -2.5);
}

TEST(AddTest, AddStringifyNeg) {
    Op* left = new Op(-10);
    Base* right = new SevenOpMock();
    Add* test = new Add(left, right);
    EXPECT_EQ(test->stringify(), "(-10+7.5)");
}
