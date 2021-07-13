#include <gtest/gtest.h>
#include "src/include/input.h"

class Input : public ::testing::Test {
 protected:
  void GetMatrix(std::vector<std::vector<int>>& matrix, std::string& input) {}
};

TEST_F(Input, SkipSpace) {
  std::cout << SkipSpace("abc") << std::endl;

  char* input = "   123  ";
  auto dis = SkipSpace(input);
  std::cout << "Skip " << dis << std::endl;
  dis = SkipSpace(input + dis + 3);
  std::cout << "Skip " << dis << std::endl;
}

TEST_F(Input, array) {
  char* input = "[     11 , 21123   , 3]";
  
  std::vector<int> array;
  auto res = AToArray(array, input);
  std::cout << "res:" << res << std::endl;
  if (res == 0) {
    for (auto item : array) {
      std::cout << item << ",";
    }
    std::cout << std::endl;
  }
}

TEST_F(Input, matrix) {

}
