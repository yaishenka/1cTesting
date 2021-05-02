//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST_F(AddTestCase, SimpleAdd) {
  EXPECT_EQ(Add(1, 1), 2);
}

TEST_F(AddTestCase, ComplAdd) {
  EXPECT_EQ(Add(Add(1, 1), 1), 3);
}