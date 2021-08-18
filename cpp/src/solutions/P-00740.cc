#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class P00740 : public ::testing::Test {
 protected:
  int deleteAndEarn(std::vector<int>& nums) {
    if (nums.size() == 0) return 0;
    const auto range = std::minmax_element(nums.begin(), nums.end());
    const int l = *(range.first);
    const int r = *(range.second);
    std::vector<int> points(r - l + 1, 0);
    for (const int num : nums) {
      points[num - l] += num;
    }
    return rob(points);
  }
 private:
  int rob(const std::vector<int>& a) {
    int prev_max = 0;
    int curr_max = 0;
    for (int i = 0; i < a.size(); ++i) {
      int tmp = curr_max;
      curr_max = std::max(curr_max, prev_max + a[i]);
      prev_max = tmp;
    }
    return curr_max;
  }
};

TEST_F(P00740, Solution) {
  std::vector<std::vector<int>> cases {
    {3,4,2},
    {2,2,3,3,3,4},
  };

  for (auto each : cases) {
    std::cout << deleteAndEarn(each) << std::endl;
  }
}
}  // namespace leetcode
