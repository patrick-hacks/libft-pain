// Copyright 2022
// Author: pfuchs

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"
#include "src/unittests/linked_list/test_list.h"

class Lstmap : public ::testing::Test {
 protected:
  void SetUp() override {
    malloc_size = INT32_MAX;
  }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

static void empty_del(void *content) {}
static void del(void *content) { free(content); }

static void *return_null(void *content) { return nullptr; }

static void *copy(void *content) {
  auto data = reinterpret_cast<Data *>(content);
  auto new_data = reinterpret_cast<Data *>(malloc(sizeof(Data)));
  new_data->a = data->a;
  new_data->b = data->b;
  return new_data;
}

TEST_F(Lstmap, Size1Copy) {
  auto list = generateTestList(1);
  auto new_list = ft_lstmap(list, copy, del);
  EXPECT_TRUE(isListUnchanged(list));
  EXPECT_TRUE(isListUnchanged(new_list));
  freeTestList(list);
  freeTestList(new_list);
}

TEST_F(Lstmap, Size10Copy) {
  auto list = generateTestList(10);
  auto new_list = ft_lstmap(list, copy, del);
  EXPECT_TRUE(isListUnchanged(list));
  EXPECT_TRUE(isListUnchanged(new_list));
  freeTestList(list);
  freeTestList(new_list);
}

TEST_F(Lstmap, Size1Empty) {
  auto list = generateTestList(1);
  auto new_list = ft_lstmap(list, return_null, empty_del);
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(list);
  freeTestList(new_list);
}

TEST_F(Lstmap, Size10Empty) {
  auto list = generateTestList(10);
  auto new_list = ft_lstmap(list, return_null, empty_del);
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(list);
  freeTestList(new_list);
}

TEST_F(Lstmap, MallocFullFail) {
  auto list = generateTestList(10);
  malloc_size = 0;
  auto new_list = ft_lstmap(list, return_null, empty_del);
  EXPECT_EQ(nullptr, new_list);
  freeTestList(list);
}

TEST_F(Lstmap, MallocFailMiddle) {
  auto list = generateTestList(10);
  malloc_size = 100;
  auto new_list = ft_lstmap(list, return_null, empty_del);
  EXPECT_EQ(nullptr, new_list);
  freeTestList(list);
}
