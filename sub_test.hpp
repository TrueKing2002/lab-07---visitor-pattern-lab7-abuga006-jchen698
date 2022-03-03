#include "op.hpp"
#include "sub.hpp"

TEST(SubTest, SubEvaluateNonZero) {
    Op* left = new Op(8);
    Base* right = new SevenOpMock();
    Sub* test = new Sub(left, right);
    EXPECT_EQ(test->evaluate(), 0.5);
}

TEST(SubTest, SubStringifyNonZero) {
    Op* left = new Op(8);
    Base* right = new SevenOpMock();
    Sub* test = new Sub(left, right);
    EXPECT_EQ(test->stringify(), "(8-7.5)");
}

TEST(SubTest, SubEvaluateZero) {
    Op* left = new Op(0);
    Base* right = new SevenOpMock();
    Sub* test = new Sub(left, right);
    EXPECT_EQ(test->evaluate(), -7.5);
}

TEST(SubTest, SubStringifyZero) {
    Op* left = new Op(0);
    Base* right = new SevenOpMock();
    Sub* test = new Sub(left, right);
    EXPECT_EQ(test->stringify(), "(0-7.5)");
}

TEST(SubTest, SubEvaluateNegative) {
    Op* left = new Op(-8);
    Base* right = new SevenOpMock();
    Sub* test = new Sub(left, right);
    EXPECT_EQ(test->evaluate(), -15.5);
}

TEST(SubTest, SubStringifyNegative) {
    Op* left = new Op(-8);
    Base* right = new SevenOpMock();
    Sub* test = new Sub(left, right);
    EXPECT_EQ(test->stringify(), "(-8-7.5)");
}
