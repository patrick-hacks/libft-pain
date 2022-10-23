// Copyright 2022
// Author: pfuchs

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"
#include "src/unittests/linked_list/test_list.h"

class LstSize : public ::testing::Test {
 protected:
  void SetUp() override {
    malloc_size = INT32_MAX;
  }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

TEST_F(LstSize, Size1) {
  auto list = generateTestList(1);
  EXPECT_EQ(1, ft_lstsize(list));
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(list);
}

TEST_F(LstSize, Size10) {
  auto list = generateTestList(10);
  EXPECT_EQ(10, ft_lstsize(list));
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(list);
}
