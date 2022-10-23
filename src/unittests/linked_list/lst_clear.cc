// Copyright 2022
// Author: pfuchs

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"
#include "src/unittests/linked_list/test_list.h"

class LstClear : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};
extern "C" {
static void delfunction(void *content) { free(content); }
}

TEST_F(LstClear, Size1) {
  auto list = generateTestList(1);
  ft_lstclear(&list, delfunction);
  EXPECT_EQ(nullptr, list);
}

TEST_F(LstClear, Size10) {
  auto list = generateTestList(10);
  ft_lstclear(&list, delfunction);
  EXPECT_EQ(nullptr, list);
}
