// Copyright 2022
// Author: pfuchs

#include <stdlib.h>

#include <cmath>

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"

class Calloc : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

TEST_F(Calloc, CorrectSize) {
  malloc_size = 13 * 8;
  char *mem = reinterpret_cast<char *>(ft_calloc(13, 8));
  for (int i = 0; i < 13 * 8; i++) {
    *mem = 1;
  }
  free_pain(mem);
}

TEST_F(Calloc, MemoryRegionZeros) {
  char *mem = reinterpret_cast<char *>(ft_calloc(2, 3));
  for (int i = 0; i < 2 * 3; i++) {
    EXPECT_EQ(0, mem[i]);
  }
  free_pain(mem);
}

TEST_F(Calloc, FirstParamZero) {
  char *mem = reinterpret_cast<char *>(ft_calloc(0, 32));
  EXPECT_EQ(nullptr, mem);
}

TEST_F(Calloc, SecondParamZero) {
  char *mem = reinterpret_cast<char *>(ft_calloc(32, 0));
  EXPECT_EQ(nullptr, mem);
}

TEST_F(Calloc, MallocFail) {
  malloc_size = 5;
  char *mem;
  ASSERT_NO_FATAL_FAILURE(
    mem = reinterpret_cast<char *>(ft_calloc(2, 3))
  );
  EXPECT_EQ(nullptr, mem);
}

// overflow by one byte
// UINT64_MAX - (274177 * 67280421310721) = -1
TEST_F(Calloc, MultiplyOverflow) {
  char *mem = reinterpret_cast<char *>(ft_calloc(274177, 67280421310721));
  EXPECT_EQ(nullptr, mem);
}
