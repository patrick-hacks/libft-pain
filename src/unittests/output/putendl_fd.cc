// Copyright 2022
// Author: pfuchs

#include <stdio.h>

#include <cstdio>

#include "gtest/gtest.h"
#include "src/unittests/libft.h"

static void output(const std::string& str, FILE* file, std::string* real) {
  ft_putendl_fd(str.c_str(), fileno(file));
  *real += str;
  *real += "\n";
}

TEST(PutendlFd, Stdout) {
  testing::internal::CaptureStdout();
  std::string real;
  output("qwe", stdout, &real);
  output("42", stdout, &real);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(real, output);
}

TEST(PutendlFd, Stderr) {
  testing::internal::CaptureStderr();
  std::string real;
  output("123", stderr, &real);
  output("42", stderr, &real);
  std::string output = testing::internal::GetCapturedStderr();
  EXPECT_EQ(real, output);
}

TEST(PutendlFd, File) {
  std::FILE* file = tmpfile();
  std::string real;
  output("137", file, &real);
  std::rewind(file);
  std::string output;
  output.resize(4);
  EXPECT_EQ(4, std::fread(output.data(), 1, 5, file));
  EXPECT_EQ(real, output);
}

TEST(PutendlFd, EmptyString) {
  testing::internal::CaptureStdout();
  std::string real;
  output("", stdout, &real);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(real, output);
}

TEST(PutendlFd, SpecialCharacters) {
  testing::internal::CaptureStdout();
  std::string real;
  output("\001\002\n\377\376", stdout, &real);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(real, output);
}
