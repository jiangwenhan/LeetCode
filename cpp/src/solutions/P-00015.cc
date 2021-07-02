#include <gtest/gtest.h>

namespace leetcode {
class P00015 : public ::testing::Test {
 protected:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    if (nums.size() < 3) {
      return std::vector<std::vector<int>>{};
    }
    std::set<std::vector<int>> rs;
    std::sort(nums.begin(), nums.end());
    size_t i, j, k;
    size_t n = nums.size();
    for (i = 0; i < n - 2; ++i) {
      j = i + 1;
      k = n - 1;
      while (j < k) {
        auto sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          rs.emplace(std::vector<int>{nums[i], nums[j], nums[k]});
          ++j;
          --k;
        } else if (sum > 0) {
          --k;
        } else {
          ++j;
        }
      }
    }
    std::vector<std::vector<int>> result(rs.begin(), rs.end());
    return result;
  }
};

TEST_F(P00015, Solution) {
  std::vector<std::vector<int>> cases = {
      std::vector<int>{-1, 0, 1, 2, -1, -4},
      std::vector<int>{},
      std::vector<int>{0},
  };

  for (auto& each_case : cases) {
    auto rs = threeSum(each_case);
    for (auto& rs_each : rs) {
      for (auto val : rs_each) {
        std::cout << val << ",";
      }
      std::cout << std::endl;
    }
  }
}
}  // namespace leetcode
