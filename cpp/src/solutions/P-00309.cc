#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class P00309 : public ::testing::Test {
 protected:
  int maxProfit(std::vector<int>& prices) {
    if (prices.empty()) return 0;
    int n = prices.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
      dp[i][1] = dp[i - 1][0] + prices[i];
      dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]);
    }
    return std::max(dp[n - 1][1], dp[n - 1][2]);
  }
};

TEST_F(P00309, Solution) {
  std::vector<std::vector<int>> cases {
    {1,2,3,0,2},
    {1},
  };

  for (auto& each : cases) {
    std::cout << maxProfit(each) << std::endl;
  }
}
}  // namespace leetcode
