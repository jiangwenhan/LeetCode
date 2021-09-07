#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class P00122 : public ::testing::Test {
 protected:
  int maxProfit(std::vector<int>& prices) {
    int ans = 0;
    for (int i = 1; i < prices.size(); ++i) {
      ans += std::max(0, prices[i] - prices[i - 1]);
    }
    return ans;
  }
};

TEST_F(P00122, Solution) {
  std::vector<std::vector<int>> cases {
    {7,1,5,3,6,4},
    {1,2,3,4,5},
    {7,6,4,3,1},
  };

  for (auto& each : cases) {
    std::cout << maxProfit(each) << std::endl;
  }
}
}  // namespace leetcode
