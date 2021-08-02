#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class P00121 : public ::testing::Test {
 protected:
  int maxProfit(std::vector<int>& prices) {
    if (prices.size() == 0) return 0;
    int max_profit = 0;
    int low_price = prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] - low_price > max_profit) {
	max_profit = prices[i] - low_price;
      }
      if (prices[i] < low_price) {
	low_price = prices[i];
      }
    }
    return max_profit;
  }
};

TEST_F(P00121, Solution) {
  std::vector<std::string> cases{
    "[7,1,5,3,6,4]",
    "[7,6,4,3,1]",
  };
  for (auto each : cases) {
    std::vector<int> prices;
    auto res = AToArray(prices, each.data());
    std::cout << "res:" << res << std::endl;
    if (res == 0) {
      std::cout << maxProfit(prices) << std::endl;
    }
  }
}
}  // namespace leetcode
