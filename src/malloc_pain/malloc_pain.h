// Copyright 2022
// Author: pfuchs

#ifndef SRC_MALLOC_PAIN_MALLOC_PAIN_H_
#define SRC_MALLOC_PAIN_MALLOC_PAIN_H_

#undef malloc
#undef free
#include <string>

extern "C" {
  extern size_t malloc_size;

  void *malloc_pain(size_t size);
  void free_pain(void *data);
}

extern size_t malloc_size;
bool is_leaking();
std::string show_leaked_memory();

#endif  // SRC_MALLOC_PAIN_MALLOC_PAIN_H_
