// Copyright 2022
// Author: pfuchs

#include <string.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(const void *s, int c, size_t n) {
  EXPECT_EQ(memchr(s, c, n), ft_memchr(s, c, n)) << "0x" << std::hex << c;
}

TEST(Memchr, Length0) {
  compare("abc", 0, 0);
  compare("abc", 'a', 0);
}

TEST(Memchr, Length1) {
  compare("abc", 0, 1);
  compare("abc", 'a', 1);
  compare("abc", 'b', 1);
}

TEST(Memchr, Length10) {
  compare("abcdefghij", 0, 10);
  compare("abcdefghij", 'a', 10);
  compare("abcdefghij", 'b', 10);
  compare("abcdefghij", 'j', 10);
  compare("abcdefghijk", 'k', 10);
}

TEST(Memchr, SearchNull) {
  compare("", 0, 1);
  compare("abc", 0, 4);
}

TEST(Memchr, SkipNull) {
  compare("\000abc", 'a', 5);
  compare("\000a\000ab", 'b', 6);
}

TEST(Memchr, Multi) {
  compare("abcabcabc", 'a', 3);
  compare("abcabcabc", 'a', 6);
  compare("abcabcabc", 'a', 9);
  compare("abcabcabc", 'c', 9);
  compare("abcabcabc", 'd', 9);
}

TEST(Memchr, CharOverflow) {
  compare("\001\002\0377\0376", '\001', 4);
  compare("\001\002\0377\0376", 0xff + 1, 4);
  compare("\001\002\0377\0376", 0xff + 255, 4);
  compare("\001\002\0377\0376", 0xff + 254, 4);
}
