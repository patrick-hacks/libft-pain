// Copyright 2022
// Author: pfuchs

#ifndef SRC_UNITTESTS_LINKED_LIST_TEST_LIST_H_
#define SRC_UNITTESTS_LINKED_LIST_TEST_LIST_H_

#include "src/unittests/libft.h"

#include <cinttypes>

struct Data {
  int64_t a;
  int64_t b;
};

t_list *generateTestList(int length);
void freeTestList(t_list *head);
bool isListUnchanged(t_list *head);

#endif  // SRC_UNITTESTS_LINKED_LIST_TEST_LIST_H_
