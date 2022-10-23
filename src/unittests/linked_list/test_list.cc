// Copyright 2022
// Author: pfuchs

#include "src/unittests/linked_list/test_list.h"

#include <stdlib.h>

#include "src/unittests/libft.h"

t_list *generateTestList(int length) {
  t_list *head = nullptr;
  for (int i = 0; i < length; i++) {
    t_list *node = reinterpret_cast<t_list *>(calloc(1, sizeof(t_list)));
    Data *data = reinterpret_cast<Data *>(calloc(1, sizeof(Data)));
    data->a = i;
    data->b = i * 2;
    node->content = data;
    node->next = head;
    head = node;
  }
  return head;
}

void freeTestList(t_list *head) {
  while (head) {
    auto temp = head->next;
    free(head->content);
    free(head);
    head = temp;
  }
}

bool isListUnchanged(t_list *head) {
  auto content = reinterpret_cast<Data*>(head->content);
  int i = content->a;
  while (head) {
    auto content = reinterpret_cast<Data*>(head->content);
    if (content->a != i || content->b != i * 2) {
      return false;
    }
    head = head->next;
    i--;
  }
  if (i == -1)
    return true;
  return false;
}
