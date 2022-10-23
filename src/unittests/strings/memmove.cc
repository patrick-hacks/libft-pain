// Copyright 2022
// Author: pfuchs

#include <string.h>

#include <algorithm>
#include <vector>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void compare(const void *src, size_t n, int offset) {
  int memory_size = n + 4 + abs(offset) * 2;
  std::vector<char> real_dst(n + 4 + abs(offset) * 2);
  std::fill(real_dst.begin(), real_dst.end(), 42);
  char *real_center = real_dst.data() + abs(offset) + 2;
  memcpy(real_center, src, n);

  std::vector<char> test_dst(real_dst);
  char *test_center = test_dst.data() + abs(offset) + 2;

  memmove(real_center, src, n);
  void *return_ptr = ft_memmove(test_center, src, n);
  EXPECT_EQ(test_center, return_ptr) << "wrong return";
  EXPECT_EQ(real_dst, test_dst) << "offset: " << offset;
}

TEST(Memmove, Length0) {
  compare("aa", 0, 0);
  compare("", 0, 0);
  compare("aa", 0, INT32_MAX);
  compare("abc", 0, INT32_MAX);
  compare("aa", 0, INT32_MIN);
  compare("abc", 0, INT32_MIN);
}

TEST(Memmove, DstEqualsSrc) {
  compare("", 0, 0);
  compare("1234567890", 4, 0);
  compare("1234567890", 8, 0);
  compare("12345678901234567890", 12, 0);
}

TEST(Memmove, DstBiggerSrc) {
  compare("1234567890", 0, 1);
  compare("1234567890", 3, 2);
  compare("1234567890", 5, 3);
  compare("1234567890", 7, 7);
}

TEST(Memmove, SrcBiggerDst) {
  compare("1234567890", 0, -1);
  compare("1234567890", 3, -2);
  compare("1234567890", 5, -3);
  compare("1234567890", 7, -7);
}

TEST(Memmove, WithNull) {
  compare("\000\001\000\377", 5, 0);
  compare("\000\001\000\377", 5, 2);
  compare("\000\001\000\377", 5, -2);
  compare("\000\001\000\377", 5, 5);
  compare("\000\001\000\377", 5, -5);
}
