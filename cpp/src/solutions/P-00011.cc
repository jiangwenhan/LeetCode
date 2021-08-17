#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class P00011 : public ::testing::Test {
 protected:
  int maxArea(std::vector<int>& height) {
    if (height.size() < 2) return 0;
    int res = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
      int area = (j - i) * std::min(height[i], height[j]);
      if (height[i] < height[j]) {
	++i;
      } else {
	--j;
      }
      res = std::max(res, area);
    }
    return res;
  }
};

TEST_F(P00011, Solution) {
  std::vector<std::vector<int>> cases{
    std::vector<int>{1,8,6,2,5,4,8,3,7},
    std::vector<int>{1,1},
    std::vector<int>{4,3,2,1,4},
    std::vector<int>{1,2,1},
  };
  for (auto each : cases) {
    std::cout << maxArea(each) << std::endl;
  }
}
}  // namespace leetcode










