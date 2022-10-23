// Copyright 2022
// Author: pfuchs

#include <stdlib.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(const char *str) { EXPECT_EQ(atoi(str), ft_atoi(str)); }

TEST(atoi, Empty) { compare(""); }

TEST(atoi, Zero) { compare("0"); }

TEST(atoi, SimplePositive) {
  compare("1");
  compare("42");
  compare("1337");
  compare("1337");
}

TEST(atoi, SimpleNegatives) {
  compare("-1");
  compare("-42");
  compare("-1337");
  compare("-1337");
}

TEST(atoi, LeadingZeros) {
  compare("01");
  compare("001");
  compare("0000000009");
  compare("-0000000999");
}

TEST(atoi, InvalidSigns) {
  compare("--9");
  compare("-+9");
  compare("+-9");
  compare("++9");
}

TEST(atoi, LeadingWhitespaces) {
  compare(" 42");
  compare("                 42");
  compare("  \n    \t   \n   \t-42");
}

TEST(atoi, InvalidCharacters) {
  compare("a42");
  compare("\00142");
  compare("a");
  compare("-a2");
  compare("+a2");
  compare("-a");
  compare("+a");
  compare("asdfghjklqwertyuiopqwertyuiop");
}

TEST(atoi, CharactersInNumber) {
  compare("123a42");
  compare("123 42");
  compare("123-42");
  compare("123+42");
  compare("123this");
  compare("0this123");
  compare("-123+42");
  compare("-123this");
  compare("-0this123");
  compare("-this123+42");
  compare("-this123this");
  compare("-this0this123");
}

TEST(atoi, IntMax) {
  compare("2147483647");
  compare("2147483647 ");
}

TEST(atoi, IntMin) {
  compare("-2147483648");
  compare("-2147483648 ");
}
