#include "op.hpp"
#include "pow.hpp"

TEST(PowTest, PowEvaluateNonZero) {
    Op* left = new Op(8);
    Base* right = new Op(7);
    Pow* test = new Pow(left, right);
    EXPECT_EQ(test->evaluate(), 2097152);
}

TEST(PowTest, PowStringifyNonZero) {
    Op* left = new Op(8);
    Base* right = new Op(7);
    Pow* test = new Pow(left, right);
    EXPECT_EQ(test->stringify(), "(8**7)");
}

TEST(PowTest, PowEvaluateZero) {
    Op* left = new Op(0);
    Base* right = new SevenOpMock();
    Pow* test = new Pow(left, right);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(PowTest, PowStringifyZero) {
    Op* left = new Op(0);
    Base* right = new SevenOpMock();
    Pow* test = new Pow(left, right);
    EXPECT_EQ(test->stringify(), "(0**7.5)");
}

TEST(PowTest, PowEvaluateZeroPower) {
    Base* left = new SevenOpMock();
    Base* right = new ZeroOpMock();
    Pow* test = new Pow(left, right);
    EXPECT_EQ(test->evaluate(), 1);
}

TEST(PowTest, PowEvaluateNegative) {
    Op* left = new Op(-8);
    Base* right = new Op(7);
    Pow* test = new Pow(left, right);
    EXPECT_EQ(test->evaluate(), -2097152);
}

TEST(PowTest, PowStringifyNegative) {
    Op* left = new Op(-8);
    Base* right = new Op(7);
    Pow* test = new Pow(left, right);
    EXPECT_EQ(test->stringify(), "(-8**7)");
}

TEST(PowTest, PowEvaluateNegativeNumberNegativePower) {
    Op* left = new Op(-8);
    Base* right = new Op(-2);
    Pow* test = new Pow(left, right);
    EXPECT_EQ(test->evaluate(), 0.015625);
}
