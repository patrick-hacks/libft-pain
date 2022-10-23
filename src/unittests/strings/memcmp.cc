// Copyright 2022
// Author: pfuchs

#include <string.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(const void *mem1, const void *mem2, size_t n) {
  int real = memcmp(mem1, mem2, n);
  int test = ft_memcmp(mem1, mem2, n);
  if (real != 0) real = real < 0 ? -1 : 1;
  if (test != 0) test = test < 0 ? -1 : 1;
  EXPECT_EQ(real, test) << "size: " << n;
}

TEST(Memcmp, Length0) {
  compare("aa", "ppp", 0);
  compare("aa", "", 0);
}

TEST(Memcmp, Length1) {
  compare("ab", "a", 1);
  compare("ab", "b", 1);
  compare("b", "ab", 1);
  compare("ab", "", 1);
}

TEST(Memcmp, Length10) {
  compare("abcdefghij", "abcdefghij", 10);
  compare("abcdefghij", "abcdefghi", 10);
  compare("abcdefghij", "abcdefghijklmnop", 10);
  compare("abcdefghij", "bbcdefghij", 10);
  compare("abcdefghij", "bbcdefghijklmnopqrstuvwxyz", 10);
}

TEST(Memcmp, CompareNull) {
  compare("", "", 1);
  compare("a", "", 1);
  compare("", "a", 1);
}

TEST(Memcmp, CompareOverNull) {
  compare("\000\000a", "\000\000b", 4);
  compare("\000\000a", "\000\000a", 4);
  compare("\000\000a", "\000\000b", 2);
  compare("\000\000a", "\000a\000", 2);
}

TEST(Memcmp, Higher) {
  compare("bbb", "caa", 4);
  compare("111", "200", 4);
}

TEST(Memcmp, Same) {
  compare("acc", "acc", 4);
  compare("199", "199", 4);
}

TEST(Memcmp, Lower) {
  compare("bbb", "acc", 4);
  compare("111", "022", 4);
}

TEST(Memcmp, SpecialChars) {
  compare("\001\002\0377\0376", "\001\002\0377\0376", 5);
  compare("\001\002\0377\0376", "\001\002\0377\0376", 3);
}
