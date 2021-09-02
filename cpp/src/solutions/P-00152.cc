#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class P00152 : public ::testing::Test {
 protected:
  int maxProduct(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int ans = nums[0];
    int curr_max = nums[0];
    int curr_min = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int temp = curr_max;
      curr_max = std::max(nums[i], std::max(curr_max * nums[i], curr_min * nums[i]));
      curr_min = std::min(nums[i], std::min(temp * nums[i], curr_min * nums[i]));
      ans = std::max(ans, curr_max);
    }
    return ans;
  }
};

TEST_F(P00152, Solution) {
  std::vector<std::vector<int>> cases {
    {2,3,-2,4},
    {-2,0,-1},
  };

  for (auto& each : cases) {
    std::cout << maxProduct(each) << std::endl;
  }
}
}  // namespace leetcode
