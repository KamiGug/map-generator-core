#include <gtest/gtest.h>
#include <iostream>

TEST(General, HelloWorld) {
  std::cout << "ax" << std::endl;
  SUCCEED(); // marks the test as passed
}
