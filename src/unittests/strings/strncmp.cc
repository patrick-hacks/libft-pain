// Copyright 2022
// Author: pfuchs

#include <string.h>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(const char *mem1, const char *mem2, size_t n) {
  int real = strncmp(mem1, mem2, n);
  int test = ft_strncmp(mem1, mem2, n);
  if (real != 0) real = real < 0 ? -1 : 1;
  if (test != 0) test = test < 0 ? -1 : 1;
  EXPECT_EQ(real, test);
}

TEST(Strncmp, BothEmpty) { compare("", "", 10); }

TEST(Strncmp, FirstEmpty) {
  compare("", "a", 1);
  compare("", "123", 10);
}

TEST(Strncmp, SecondEmpty) {
  compare("a", "", 1);
  compare("123", "", 3);
}

TEST(Strncmp, Length0) {
  compare("aa", "ppp", 0);
  compare("aa", "", 0);
}

TEST(Strncmp, Length1) {
  compare("ab", "a", 1);
  compare("ab", "b", 1);
  compare("b", "ab", 1);
  compare("ab", "", 1);
}

TEST(Strncmp, Length10) {
  compare("abcdefghij", "abcdefghij", 10);
  compare("abcdefghij", "abcdefghi", 10);
  compare("abcdefghij", "abcdefghijklmnop", 10);
  compare("abcdefghij", "bbcdefghij", 10);
  compare("abcdefghij", "bbcdefghijklmnopqrstuvwxyz", 10);
}

TEST(Strncmp, CompareNull) {
  compare("", "", 1);
  compare("a", "", 1);
  compare("", "a", 1);
}

TEST(Strncmp, CompareOverNull) {
  compare("a\000\000a", "a\000\000b", 4);
  compare("b\000\000a", "b\000\000a", 4);
  compare("\000\000a", "\000\000b", 2);
  compare("\000\000a", "\000a\000", 2);
}

TEST(Strncmp, Higher) {
  compare("bbb", "caa", 4);
  compare("111", "200", 4);
}

TEST(Strncmp, Same) {
  compare("acc", "acc", 4);
  compare("199", "199", 4);
}

TEST(Strncmp, Lower) {
  compare("bbb", "acc", 4);
  compare("111", "022", 4);
}

TEST(Strncmp, SpecialChars) {
  compare("\001\002\0377\0376", "\001\002\0377\0376", 5);
  compare("\001\002\0377\0376", "\001\002\0377\0376", 3);
}

TEST(Strncmp, MaxSize) {
    compare("abcdefghij", "abcdefghij", SIZE_MAX);
  compare("abcdefghij", "abcdefghi", SIZE_MAX);
  compare("abcdefghij", "abcdefghijklmnop", SIZE_MAX);
  compare("abcdefghij", "bbcdefghij", SIZE_MAX);
  compare("abcdefghij", "bbcdefghijklmnopqrstuvwxyz", SIZE_MAX);
}
