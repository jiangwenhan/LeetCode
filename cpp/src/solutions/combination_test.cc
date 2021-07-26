#include <gtest/gtest.h>
#include "src/include/algorithms/combination.h"
#include "src/include/output.h"

class CombinationTest : public ::testing::Test {
 protected:
};

TEST_F(CombinationTest, Combine) {
  std::vector<int> array {1, 2, 3, 4, 5};
  int m = 3;
  auto result = combination(array, m);
  for (auto each : result) {
    PrintArray(each);
  }
}

