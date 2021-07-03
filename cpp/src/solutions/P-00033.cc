#include <gtest/gtest.h>

namespace leetcode {
class P00033 : public ::testing::Test {
 protected:
  int search(std::vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > nums[low]) {
        if (nums[low] <= target && target < nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else if (nums[mid] < nums[high]) {
        if (nums[mid] < target && target <= nums[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      } else {
        if (nums[low] == nums[mid]) {
          ++low;
        }
        if (nums[mid] == nums[high]) {
          --high;
        }
      }
    }
    return -1;
  }
};

TEST_F(P00033, Solution) {
  std::vector<std::tuple<std::vector<int>, int>> cases = {
      std::tuple<std::vector<int>, int>(std::vector<int>{4, 5, 6, 7, 0, 1, 2}, 0),
      std::tuple<std::vector<int>, int>(std::vector<int>{4, 5, 6, 7, 0, 1, 2}, 3),
      std::tuple<std::vector<int>, int>(std::vector<int>{1}, 0),
  };

  for (auto& each : cases) {
    std::cout << search(std::get<0>(each), std::get<1>(each)) << std::endl;
  }
}
}  // namespace leetcode
