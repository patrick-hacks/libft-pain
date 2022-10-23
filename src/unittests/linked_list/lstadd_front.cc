// Copyright 2022
// Author: pfuchs

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"
#include "src/unittests/linked_list/test_list.h"

class LstaddFront : public ::testing::Test {
 protected:
  void SetUp() override {
    malloc_size = INT32_MAX;
  }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

TEST_F(LstaddFront, Size0) {
  t_list* list = nullptr;
  auto test_list = list;
  auto node = generateTestList(1);
  ft_lstadd_front(&test_list, node);
  EXPECT_EQ(test_list, node);
  EXPECT_EQ(test_list->next, list);
  freeTestList(test_list);
}

TEST_F(LstaddFront, Size1) {
  auto list = generateTestList(1);
  auto test_list = list;
  auto node = generateTestList(1);
  ft_lstadd_front(&test_list, node);
  EXPECT_EQ(test_list, node);
  EXPECT_EQ(test_list->next, list);
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(test_list);
}

TEST_F(LstaddFront, Size10) {
  auto list = generateTestList(10);
  auto test_list = list;
  auto node = generateTestList(1);
  ft_lstadd_front(&test_list, node);
  EXPECT_EQ(test_list, node);
  EXPECT_EQ(test_list->next, list);
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(test_list);
}