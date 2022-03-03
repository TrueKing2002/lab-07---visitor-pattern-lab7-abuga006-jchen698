#include "op.hpp"
#include "div.hpp"

TEST(DivTest, DivEvaluateNormal) {
    Op* left = new Op(75);
    Base* right = new SevenOpMock();
    Div* test = new Div(left, right);
    EXPECT_EQ(test->evaluate(), 10);
}

TEST(DivTest, DivStringifyNormal) {
    Op* left = new Op(75);
    Base* right = new SevenOpMock();
    Div* test = new Div(left, right);
    EXPECT_EQ(test->stringify(), "(75/7.5)");
}

TEST(DivTest, DivEvaulateZero) {
    Op* left = new Op(0);
    Base* right = new SevenOpMock();
    Div* test = new Div(left, right);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivEvaluateZero) {
    Op* left = new Op(0);
    Base* right = new SevenOpMock();
    Div* test = new Div(left, right);
    EXPECT_EQ(test->stringify(), "(0/7.5)");
}

TEST(DivTest, DivEvaluateNeg) {
    Op* left = new Op(-75);
    Base* right = new SevenOpMock();
    Div* test = new Div(left, right);
    EXPECT_EQ(test->evaluate(), -10);
}

TEST(DivTest, DivStringifyNeg) {
    Op* left = new Op(-75);
    Base* right = new SevenOpMock();
    Div* test = new Div(left, right);
    EXPECT_EQ(test->stringify(), "(-75/7.5)");
}

TEST(DivTest, DivEvaluateUndefined) {
    Op* left = new Op(75);
    Op* right = new Op(0);
    Div* test = new Div(left, right);
    EXPECT_EQ(test->evaluate(), std::numeric_limits<double>::infinity());
}

TEST(DivTest, DivStringifyUndefined) {
    Op* left = new Op(75);
    Op* right = new Op(0);
    Div* test = new Div(left, right);
    EXPECT_EQ(test->stringify(), "(75/0)");
}
