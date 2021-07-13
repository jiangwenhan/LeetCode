#include <gtest/gtest.h>

namespace leetcode {
class P00054 : public ::testing::Test {
 protected:
  enum DIRECTION {
    LEFT2RIGHT,
    TOP2BOTTOM,
    RIGHT2LEFT,
    BOTTOM2TOP,
  };
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result;
    int left = 0, top = 0;
    int bottom = matrix.size() - 1;
    if (matrix.size() == 0) {
      return result;
    }
    int right = matrix[0].size() - 1;
    DIRECTION direction = LEFT2RIGHT;
    while (left <= right && top <= bottom) {
      if (LEFT2RIGHT == direction) {
        for (auto i = left; i <= right; ++i) {
          result.emplace_back(matrix[top][i]);
        }
        top++;
        direction = TOP2BOTTOM;
      } else if (TOP2BOTTOM == direction) {
        for (auto i = top; i <= bottom; ++i) {
          result.emplace_back(matrix[i][right]);
        }
        right--;
        direction = RIGHT2LEFT;
      } else if (RIGHT2LEFT == direction) {
        for (auto i = right; i >= left; --i) {
          result.emplace_back(matrix[bottom][i]);
        }
        bottom--;
        direction = BOTTOM2TOP;
      } else if (BOTTOM2TOP == direction) {
        for (auto i = bottom; i >= top; --i) {
          result.emplace_back(matrix[i][left]);
        }
        left++;
        direction = LEFT2RIGHT;
      }
    }
    return result;
  }
};  // namespace leetcode

TEST_F(P00054, Solution) {
  std::vector<std::vector<std::vector<int>>> cases = {
      std::vector<std::vector<int>>{
          std::vector<int>{1, 2, 3},
          std::vector<int>{4, 5, 6},
          std::vector<int>{7, 8, 9},
      },
      std::vector<std::vector<int>>{
          std::vector<int>{1, 2, 3, 4},
          std::vector<int>{5, 6, 7, 8},
          std::vector<int>{9, 10, 11, 12},
      },
  };

  for (auto& each : cases) {
    auto res = spiralOrder(each);
    for (auto item : res) {
      std::cout << item << ",";
    }
    std::cout << std::endl;
  }
}
}  // namespace leetcode
