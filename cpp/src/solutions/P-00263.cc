#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class P00263 : public ::testing::Test {
 protected:
  bool isUgly(int n) {
    if (n <= 0) return false;
    std::vector<int> factors {2, 3, 5};
    for (auto factor : factors) {
      while (n % factor == 0) {
	n /= factor;
      }
    }
    return n == 1;
  }
};

TEST_F(P00263, Solution) {
  std::vector<int> cases {6, 8, 14, 1};
  for (auto each : cases) {
    std::cout << std::boolalpha << isUgly(each) << std::endl;
  }
}
}  // namespace leetcode
