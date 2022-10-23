// Copyright 2022
// Author: pfuchs

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"
#include "src/unittests/linked_list/test_list.h"

class LstaddBack : public ::testing::Test {
 protected:
  void SetUp() override {
    malloc_size = INT32_MAX;
  }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

TEST_F(LstaddBack, Size0) {
  t_list* list = nullptr;
  auto test_list = list;
  auto node = generateTestList(1);
  ft_lstadd_back(&test_list, node);
  EXPECT_EQ(test_list, node);
  EXPECT_EQ(test_list->next, list);
  freeTestList(test_list);
}

TEST_F(LstaddBack, Size1) {
  auto list = generateTestList(1);
  auto test_list = list;
  auto node = generateTestList(1);
  ft_lstadd_back(&test_list, node);
  EXPECT_EQ(test_list, list);
  EXPECT_EQ(test_list->next, node);
  EXPECT_TRUE(isListUnchanged(node));
  freeTestList(test_list);
}

TEST_F(LstaddBack, Size10) {
  auto list = generateTestList(10);
  auto test_list = list;
  auto node = generateTestList(1);
  ft_lstadd_back(&test_list, node);
  EXPECT_EQ(test_list, list);
  EXPECT_TRUE(isListUnchanged(node));
  freeTestList(test_list);
}
