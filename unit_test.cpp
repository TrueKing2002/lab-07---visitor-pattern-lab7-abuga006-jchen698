#include "gtest/gtest.h"

#include "op_test.hpp"

#include "seven_op_mock.hpp"
#include "negative_seven_op_mock.hpp"
#include "zero_op_mock.hpp"

#include "mult_test.hpp"

#include "div_test.hpp"

#include "sub_test.hpp"

#include "add_test.hpp"

#include "pow_test.hpp"



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
