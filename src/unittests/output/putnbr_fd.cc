// Copyright 2022
// Author: pfuchs

#include <stdio.h>

#include <cstdio>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void output(int n, FILE* file, std::string* real) {
  ft_putnbr_fd(n, fileno(file));
  *real += std::to_string(n);
}

TEST(PutnbrFd, Stdout) {
  testing::internal::CaptureStdout();
  std::string real;
  output(42, stdout, &real);
  output(1337, stdout, &real);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(real, output);
}

TEST(PutnbrFd, Stderr) {
  testing::internal::CaptureStderr();
  std::string real;
  output(123123, stderr, &real);
  output(420, stderr, &real);
  std::string output = testing::internal::GetCapturedStderr();
  EXPECT_EQ(real, output);
}

TEST(PutnbrFd, File) {
  std::FILE* file = tmpfile();
  std::string real;
  output(1337, file, &real);
  std::rewind(file);
  std::string output;
  output.resize(4);
  EXPECT_EQ(4, std::fread(output.data(), 1, 5, file));
  EXPECT_EQ(real, output);
}

TEST(PutnbrFd, SpecialNumbers) {
  testing::internal::CaptureStdout();
  std::string real;
  output(0, stdout, &real);
  output(-1, stdout, &real);
  output(1, stdout, &real);
  output(INT32_MAX, stdout, &real);
  output(INT32_MIN, stdout, &real);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(real, output);
}
