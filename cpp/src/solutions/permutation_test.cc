#include <gtest/gtest.h>
#include "src/include/algorithms/permutation.h"
#include "src/include/output.h"

class PermutationTest : public ::testing::Test {
 protected:
};

TEST_F(PermutationTest, Permute) {
  std::vector<int> array {1, 2, 3};
  auto result = permutation(array);
  for (auto each : result) {
    PrintArray(each);
  }
}

