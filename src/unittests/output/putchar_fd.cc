// Copyright 2022
// Author: pfuchs

#include <stdio.h>

#include <cstdio>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void output(char c, FILE* file, std::string* real) {
  ft_putchar_fd(c, fileno(file));
  real->push_back(c);
}

TEST(PutcharFd, Stdout) {
  testing::internal::CaptureStdout();
  std::string real;
  output('4', stdout, &real);
  output('2', stdout, &real);
  output(0, stdout, &real);
  output('z', stdout, &real);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(real, output);
}

TEST(PutcharFd, Stderr) {
  testing::internal::CaptureStderr();
  std::string real;
  output('4', stderr, &real);
  output('2', stderr, &real);
  output(0, stderr, &real);
  output('z', stderr, &real);
  std::string output = testing::internal::GetCapturedStderr();
  EXPECT_EQ(real, output);
}

TEST(PutcharFd, File) {
  std::FILE* file = tmpfile();
  std::string real;
  output('4', file, &real);
  output('2', file, &real);
  output(0, file, &real);
  output('z', file, &real);
  std::rewind(file);
  std::string output;
  output.resize(4);
  EXPECT_EQ(4, std::fread(output.data(), 1, 5, file));
  EXPECT_EQ(real, output);
}
