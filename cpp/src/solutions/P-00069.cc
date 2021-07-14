#include <gtest/gtest.h>

namespace leetcode {
class P00069 : public ::testing::Test {
 protected:
  int mySqrt(int x) {
    if (x == 0) return 0;
    int low = 1;
    int high = x;
    int res = 0;
    int mid = 0;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (mid < x / mid) {
        low = mid + 1;
        res = mid;
      } else if (mid == x / mid) {
        return mid;
      } else {
        high = mid - 1;
      }
    }
    return res;
  }
};

TEST_F(P00069, Solution) {
  std::vector<int> cases {0, 1, 2, 4, 8, 9, 2147395599};
  for (auto each : cases) {
    std::cout << mySqrt(each) << std::endl;
  }
}
}  // namespace leetcode
