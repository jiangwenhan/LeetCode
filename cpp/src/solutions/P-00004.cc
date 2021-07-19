#include <gtest/gtest.h>

namespace leetcode {
class P00004 : public ::testing::Test {
 protected:
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    double median = 0.0;
    if (nums1.size() == 0 && nums2.size() == 0) return median;
    size_t i = 0, j = 0, count = 0;
    size_t total = nums1.size() + nums2.size();
    bool is_odd = total % 2 == 0 ? false : true;
    int prev = 0, current = 0;
    for (;;) {
      if (count > total / 2) {
        break;
      }
      int lhs = INT_MAX, rhs = INT_MAX;
      if (i < nums1.size()) {
        lhs = nums1[i];
      }
      if (j < nums2.size()) {
        rhs = nums2[j];
      }

      prev = current;
      if (lhs < rhs) {
        current = nums1[i++];
      } else {
        current = nums2[j++];
      }
      ++count;
    }

    return is_odd ? double(current) : double(prev + current) / 2.0;
  }
};

TEST_F(P00004, Solution) {
  std::vector<std::tuple<std::vector<int>, std::vector<int>>> cases = {
      std::tuple<std::vector<int>, std::vector<int>>(std::vector<int>{1, 3}, std::vector<int>{2}),
      std::tuple<std::vector<int>, std::vector<int>>(std::vector<int>{1, 2},
                                                     std::vector<int>{3, 4}),
      std::tuple<std::vector<int>, std::vector<int>>(std::vector<int>{0, 0},
                                                     std::vector<int>{0, 0}),
      std::tuple<std::vector<int>, std::vector<int>>(std::vector<int>{}, std::vector<int>{1}),
      std::tuple<std::vector<int>, std::vector<int>>(std::vector<int>{2}, std::vector<int>{}),
  };

  for (auto& each : cases) {
    auto& nums1 = std::get<0>(each);
    auto& nums2 = std::get<1>(each);
    std::cout << findMedianSortedArrays(nums1, nums2) << std::endl;
  }
}
}  // namespace leetcode
