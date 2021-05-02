//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST_F(LeapTestCase, LeapYear) {
  EXPECT_EQ(IsLeap(2020), true);
}

TEST_F(LeapTestCase, LeapYear4000) {
  EXPECT_EQ(IsLeap(4000), true);
}

TEST_F(LeapTestCase, LeapYear4100) {
  EXPECT_EQ(IsLeap(4100), false);
}

TEST_F(LeapTestCase, NotLeapYear) {
  EXPECT_EQ(IsLeap(2021), false);
}

TEST_F(LeapTestCase, InvalidYear) {
  EXPECT_THROW(IsLeap(-1), std::invalid_argument);
}

TEST_F(LeapTestCase, DaysInJan) {
  EXPECT_EQ(GetMonthDays(2021, 1), 31);
}

TEST_F(LeapTestCase, DaysInLeapFebr) {
  EXPECT_EQ(GetMonthDays(2020, 2), 29);
}

TEST_F(LeapTestCase, DaysInNotLeapFebr) {
  EXPECT_EQ(GetMonthDays(2021, 2), 28);
}

TEST_F(LeapTestCase, DaysInApril) {
  EXPECT_EQ(GetMonthDays(2021, 4), 30);
}

TEST_F(LeapTestCase, DaysInMay) {
  EXPECT_EQ(GetMonthDays(2021, 5), 31);
}

TEST_F(LeapTestCase, DaysInJun) {
  EXPECT_EQ(GetMonthDays(2021, 6), 30);
}

TEST_F(LeapTestCase, DaysInJul) {
  EXPECT_EQ(GetMonthDays(2021, 7), 31);
}

TEST_F(LeapTestCase, DaysInAug) {
  EXPECT_EQ(GetMonthDays(2021, 8), 31);
}

TEST_F(LeapTestCase, DaysInSept) {
  EXPECT_EQ(GetMonthDays(2021, 9), 30);
}

TEST_F(LeapTestCase, DaysInOct) {
  EXPECT_EQ(GetMonthDays(2021, 10), 31);
}

TEST_F(LeapTestCase, DaysInNov) {
  EXPECT_EQ(GetMonthDays(2021, 11), 30);
}

TEST_F(LeapTestCase, DaysInDec) {
  EXPECT_EQ(GetMonthDays(2021, 12), 31);
}

TEST_F(LeapTestCase, InvalidInputMonthEqToZero) {
  EXPECT_THROW(GetMonthDays(2021, 0), std::invalid_argument);
}

TEST_F(LeapTestCase, InvalidInputMonthLessThenZero) {
  EXPECT_THROW(GetMonthDays(2021, -1), std::invalid_argument);
}

TEST_F(LeapTestCase, InvalidInыфputMonthGreaterThenTwelwe) {
  EXPECT_THROW(GetMonthDays(2021, 13), std::invalid_argument);
}

TEST_F(LeapTestCase, InvalidInputYear) {
  EXPECT_THROW(GetMonthDays(-1, 2), std::invalid_argument);
}