#include <gtest/gtest.h>

namespace leetcode {
class P00064 : public ::testing::Test {
 protected:
  int minPathSum(std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = 0;
    if (grid.size() > 0) {
      n = grid[0].size();
    }

    std::vector<std::vector<int>> sum;
    for (int i = 0; i < m; ++i) {
      std::vector<int> colomn(n);
      sum.emplace_back(colomn);
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0) {
          sum[i][j] = grid[i][j];
        } else if (i == 0 && j > 0) {
          sum[i][j] = sum[i][j - 1] + grid[i][j];
        } else if (i > 0 && j == 0) {
          sum[i][j] = sum[i - 1][j] + grid[i][j];
        } else {
          sum[i][j] = std::min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
        }
      }
    }
    return sum[m - 1][n - 1];
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
