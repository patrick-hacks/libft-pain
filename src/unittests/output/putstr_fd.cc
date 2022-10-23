// Copyright 2022
// Author: pfuchs

#include <stdio.h>

#include <cstdio>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void output(const std::string& str, FILE* file, std::string* real) {
  ft_putstr_fd(str.c_str(), fileno(file));
  *real += str;
}

TEST(PutstrFd, Stdout) {
  testing::internal::CaptureStdout();
  std::string real;
  output("qwe", stdout, &real);
  output("42", stdout, &real);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(real, output);
}

TEST(PutstrFd, Stderr) {
  testing::internal::CaptureStderr();
  std::string real;
  output("123", stderr, &real);
  output("42", stderr, &real);
  std::string output = testing::internal::GetCapturedStderr();
  EXPECT_EQ(real, output);
}

TEST(PutstrFd, File) {
  std::FILE* file = tmpfile();
  std::string real;
  output("1337", file, &real);
  std::rewind(file);
  std::string output;
  output.resize(4);
  EXPECT_EQ(4, std::fread(output.data(), 1, 5, file));
  EXPECT_EQ(real, output);
}

TEST(PutstrFd, EmptyString) {
  testing::internal::CaptureStdout();
  std::string real;
  output("", stdout, &real);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(real, output);
}

TEST(PutstrFd, SpecialCharacters) {
  testing::internal::CaptureStdout();
  std::string real;
  output("\001\002\377\376", stdout, &real);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(real, output);
}
