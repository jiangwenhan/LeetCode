#include <gtest/gtest.h>

namespace leetcode {
class P00048 : public ::testing::Test {
 protected:
  void rotate(std::vector<std::vector<int>>& matrix) {
    if (matrix.size() == 1) {
      return;
    }

    for (std::size_t i = 0; i < matrix.size() / 2; ++i) {
      auto tmp = matrix[i];
      matrix[i] = matrix[matrix.size() - i - 1];
      matrix[matrix.size() - i - 1] = tmp;
    }

    for (std::size_t i = 0; i < matrix.size(); ++i) {
      for (std::size_t j = i; j < matrix.size(); ++j) {
        if (i == j) continue;
        auto tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
      }
    }
  }
};

TEST_F(P00048, Solution) {
  std::vector<std::vector<int>> case1 = {
      std::vector<int>{1, 2, 3},
      std::vector<int>{4, 5, 6},
      std::vector<int>{7, 8, 9},
  };

  rotate(case1);

  for (auto& each : case1) {
    for (auto item : each) {
      std::cout << item << ",";
    }
    std::cout << std::endl;
  }

  std::vector<std::vector<int>> case2 = {
      std::vector<int>{5, 1, 9, 11},
      std::vector<int>{2, 4, 8, 10},
      std::vector<int>{13, 3, 6, 7},
      std::vector<int>{15, 14, 12, 16},
  };

  rotate(case2);

  for (auto& each : case2) {
    for (auto item : each) {
      std::cout << item << ",";
    }
    std::cout << std::endl;
  }

  std::vector<std::vector<int>> case3 = {
    std::vector<int>{1},
  };

  rotate(case3);

  for (auto& each : case3) {
    for (auto item : each) {
      std::cout << item << ",";
    }
    std::cout << std::endl;
  }

  std::vector<std::vector<int>> case4 = {
    std::vector<int>{1, 2},
    std::vector<int>{3, 4},
  };

  rotate(case4);

  for (auto& each : case4) {
    for (auto item : each) {
      std::cout << item << ",";
    }
    std::cout << std::endl;
  }

}
}  // namespace leetcode
