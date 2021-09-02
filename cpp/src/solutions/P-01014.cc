#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class P01014 : public ::testing::Test {
 protected:
  int maxScoreSightseeingPair(std::vector<int>& values) {
    int ans = 0;
    int curr_max = values[0] + 0;
    for (int i = 1; i < values.size(); ++i) {
      ans = std::max(ans, curr_max + values[i] - i);
      curr_max = std::max(curr_max, values[i] + i);
    }
    return ans;
  }
};

TEST_F(P01014, Solution) {
  std::vector<std::vector<int>> cases {
    {8,1,5,2,6},
    {1,2},
  };

  for (auto& each : cases) {
    std::cout << maxScoreSightseeingPair(each) << std::endl;
  }
}
}  // namespace leetcode
