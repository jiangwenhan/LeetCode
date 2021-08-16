#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class STO00042 : public ::testing::Test {
 protected:
  int maxSubArray(std::vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    
    std::vector<int> dp(nums.size(), 0);
    int res = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (dp[i - 1] > 0) {
	dp[i] = dp[i - 1] + nums[i];
      } else {
	dp[i] = nums[i];
      }
      res = std::max(res, dp[i]);
    }
    return res;
  }
};

TEST_F(STO00042, Solution) {
  std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
  std::cout << maxSubArray(nums) << std::endl;
}
}  // namespace leetcode
