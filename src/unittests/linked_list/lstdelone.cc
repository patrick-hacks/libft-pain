// Copyright 2022
// Author: pfuchs

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"
#include "src/unittests/linked_list/test_list.h"

class Lstdelone : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

static void delfunction(void *content) { free_pain(content); }

static void do_nothing(void *content) { }

TEST_F(Lstdelone, Simple) {
  auto list = generateTestList(1);
  ft_lstdelone(list, delfunction);
}

TEST_F(Lstdelone, UsedTheFunction) {
  auto list = generateTestList(1);
  auto content = list->content;
  ft_lstdelone(list, do_nothing);
  free_pain(content);
}
