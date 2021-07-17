#include <gtest/gtest.h>

#include "src/include/algorithms/swap.h"

namespace leetcode {
class P00046 : public ::testing::Test {
 protected:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    dfs(result, nums, 0);
    return result;
  }

 private:
  void dfs(std::vector<std::vector<int>>& result, std::vector<int>& nums, int index) {
    if (index >= nums.size()) {
      result.emplace_back(nums);
    }
    for (int i = index; i < nums.size(); ++i) {
      swap(nums, i, index);
      dfs(result, nums, index + 1);
      swap(nums, i, index);
    }
  }
};

TEST_F(P00046, Solution) {
  std::vector<std::vector<int>> cases = {
      std::vector<int>{1, 2, 3},
      std::vector<int>{0, 1},
      std::vector<int>{1},
  };

  for (auto& each : cases) {
    auto result = permute(each);
    for (auto& res : result) {
      for (auto item : res) {
        std::cout << item << ",";
      }
      std::cout << std::endl;
    }
  }
}
}  // namespace leetcode
