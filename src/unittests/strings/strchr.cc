// Copyright 2022
// Author: pfuchs

#include <string.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(const char *s, int c) {
  EXPECT_EQ(strchr(s, c), ft_strchr(s, c));
}

TEST(Strchr, EmptyString) {
  compare("", 'a');
  compare("", '4');
}

TEST(Strchr, SingleChar) {
  compare("a", 'a');
  compare("y", 'y');
}

TEST(Strchr, LongString) {
  compare("12345678901234567890ayghujiko", 'a');
  compare("12345678901234567890ayghujiko", 'k');
  compare("1234567890234567890ayghujiko", '1');
}

TEST(Strchr, MultipleInstances) {
  compare("1234561234512345123456", '2');
  compare("1234561234512345123456", '6');
}

TEST(Strchr, SearchNull) {
  compare("", 0);
  compare("a", 0);
  compare("1234567890", 0);
}

TEST(Strchr, NotFound) {
  compare("abc", 'd');
  compare("abc", 'd');
}

TEST(Strchr, EndOnNull) {
  compare("abc\000yyui", 'y');
  compare("abc\000yyui", 'u');
}

TEST(Strchr, CharOverflow) {
  compare("\001\002\0377\0376", '\001');
  compare("\001\002\0377\0376", 0xff + 255);
  compare("\001\002\0377\0376", 0xff + 254);
}

TEST(Strchr, CharOverflowToNull) {
  compare("\001\002\0377\0376", 0xff + 1);
}
