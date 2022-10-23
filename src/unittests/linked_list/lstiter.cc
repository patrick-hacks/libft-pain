// Copyright 2022
// Author: pfuchs

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"
#include "src/unittests/linked_list/test_list.h"

class Lstiter : public ::testing::Test {
 protected:
  void SetUp() override {
    malloc_size = INT32_MAX;
  }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

static void nothing(void *content) {}

static void increment(void *content) {
  auto data = reinterpret_cast<Data *>(content);
  data->a += 1;
  data->b += 2;
}

static void decrement(void *content) {
  auto data = reinterpret_cast<Data *>(content);
  data->a -= 1;
  data->b -= 2;
}

TEST_F(Lstiter, Size1NoChange) {
  auto list = generateTestList(1);
  ft_lstiter(list, nothing);
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(list);
}

TEST_F(Lstiter, Size1Change) {
  auto list = generateTestList(1);
  ft_lstiter(list, increment);
  EXPECT_FALSE(isListUnchanged(list));
  ft_lstiter(list, decrement);
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(list);
}

TEST_F(Lstiter, Size10NoChange) {
  auto list = generateTestList(10);
  ft_lstiter(list, nothing);
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(list);
}

TEST_F(Lstiter, Size10Change) {
  auto list = generateTestList(10);
  ft_lstiter(list, increment);
  EXPECT_FALSE(isListUnchanged(list));
  ft_lstiter(list, decrement);
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(list);
}
