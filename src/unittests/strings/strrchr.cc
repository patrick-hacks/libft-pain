// Copyright 2022
// Author: pfuchs

#include <string.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(const char *s, int c) {
  EXPECT_EQ(strrchr(s, c), ft_strrchr(s, c));
}

TEST(Strrchr, EmptyString) {
  compare("", 'a');
  compare("", '4');
}

TEST(Strrchr, SingleChar) {
  compare("a", 'a');
  compare("y", 'y');
}

TEST(Strrchr, LongString) {
  compare("12345678901234567890ayghujiko", 'a');
  compare("12345678901234567890ayghujiko", 'k');
  compare("1234567890234567890ayghujiko", '1');
}

TEST(Strrchr, MultipleInstances) {
  compare("1234561234512345123456", '2');
  compare("1234561234512345123456", '6');
}

TEST(Strrchr, SearchNull) {
  compare("", 0);
  compare("a", 0);
  compare("1234567890", 0);
}

TEST(Strrchr, NotFound) {
  compare("abc", 'd');
  compare("abc", 'd');
}

TEST(Strrchr, EndOnNull) {
  compare("abc\000yyui", 'y');
  compare("abc\000yyui", 'u');
}

TEST(Strrchr, CharOverflow) {
  compare("\001\002\0377\0376", '\001');
  compare("\001\002\0377\0376", 0xff + 255);
  compare("\001\002\0377\0376", 0xff + 254);
}

TEST(Strrchr, CharOverflowToNull) {
  compare("\001\002\0377\0376", 0xff + 1);
}
