#include <gtest/gtest.h>

namespace leetcode {
class P00064 : public ::testing::Test {
 protected:
  int minPathSum(std::vector<std::vector<int>>& grid) {
    int sum = 0;
    return sum;
  }
};

TEST_F(P00064, Solution) {
  std::vector<std::vector<std::vector<int>>> cases{
      std::vector<std::vector<int>>{
          std::vector<int>{1, 3, 1},
          std::vector<int>{1, 5, 1},
          std::vector<int>{4, 2, 1},
      },
      std::vector<std::vector<int>>{
          std::vector<int>{1, 2, 3},
          std::vector<int>{4, 5, 6},
      },
  };

  for (auto& each : cases) {
    std::cout << minPathSum(each) << std::endl;
  }
}
}  // namespace leetcode
