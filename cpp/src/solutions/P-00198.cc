#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class P00198 : public ::testing::Test {
 protected:
  int rob(std::vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    std::vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); ++i) {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[nums.size() - 1];
  }
};

TEST_F(P00198, Solution) {
  std::vector<std::vector<int>> cases{
    {1,2,3,1},
    {2,7,9,3,1},
  };

  for (auto each : cases) {
    std::cout << rob(each) << std::endl;
  }
}
}  // namespace leetcode
