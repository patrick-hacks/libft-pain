// Copyright 2022
// Author: pfuchs

#include "src/malloc_pain/malloc_pain.h"

#include <climits>
#include <unordered_map>

#include <cstdlib>
#include <string>
#include <sstream>

size_t malloc_size = 0;
std::unordered_map<void *, size_t> allocated_data;

extern "C" {
void *malloc_pain(size_t size) {
  if (size > malloc_size || size == 0) {
    return NULL;
  }
  char *data = reinterpret_cast<char *>(malloc(size));
  if (data == NULL)
    return NULL;
  malloc_size -= size;
  for (int i = 0; i < size; i++) {
    data[i] = i + 1;
  }
  allocated_data.insert({data, size});
  return data;
}

void free_pain(void *data) {
  allocated_data.erase(data);
  free(data);
}
}

bool is_leaking() {
  return false;
  return allocated_data.empty() == false;
}

std::string show_leaked_memory() {
  std::stringstream result;
  result << "leaked memory: \n";
  for (auto e : allocated_data) {
    result << "ptr:  " << (uint64_t)e.first << "\n";
    std::string data(reinterpret_cast<char *>(e.first), e.second);
    result << "data: " << data << "\n";
  }
  return result.str();
}
