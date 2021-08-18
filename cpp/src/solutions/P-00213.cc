#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class P00213 : public ::testing::Test {
 protected:
  int rob(std::vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return std::max(nums[0], nums[1]);
    return std::max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
  }

 private:
  int rob(std::vector<int>& nums, int start, int end) {
    int prev_max = nums[start];
    int curr_max = std::max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; ++i) {
      int tmp = curr_max;
      curr_max = std::max(curr_max, prev_max + nums[i]);
      prev_max = tmp;
    }
    return curr_max;
  }
};

TEST_F(P00213, Solution) {
  std::vector<std::vector<int>> cases {
    {2,3,2},
    {1,2,3,1},
    {0},
  };

  for (auto each : cases) {
    std::cout << rob(each) << std::endl;
  }
}
}  // namespace leetcode
