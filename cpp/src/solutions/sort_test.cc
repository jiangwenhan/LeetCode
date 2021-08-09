#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"
#include "src/include/algorithms/sort.h"

namespace leetcode {
class SortTest : public ::testing::Test {
 protected:
};

TEST_F(SortTest, SelectionSort) {
  std::vector<int> array {
    8,2,6,3,10,9,4,1,7,5,
  };
  selection_sort(array);
  PrintArray(array);
}

TEST_F(SortTest, BubbleSort) {
  std::vector<int> array {
    8,2,6,3,10,9,4,1,7,5,
  };
  bubble_sort(array);
  PrintArray(array);
}

TEST_F(SortTest, InsertionSort) {
  std::vector<int> array {
    8,2,6,3,10,9,4,1,7,5,
  };
  insertion_sort(array);
  PrintArray(array);
}

TEST_F(SortTest, CountingSort) {
  std::vector<int> array {
    8,2,6,3,10,9,4,1,7,5,
  };
  counting_sort(array);
  PrintArray(array);
}

TEST_F(SortTest, RadixSort) {
  std::vector<int> array {
    8,2,6,3,10,9,4,1,7,5,
  };
  radix_sort(array);
  PrintArray(array);
}

TEST_F(SortTest, QuickSort) {
  std::vector<int> array {
    8,2,6,3,10,9,4,1,7,5,
  };
  quick_sort(array);
  PrintArray(array);
}

TEST_F(SortTest, MergeSort) {
  std::vector<int> array {
    8,2,6,3,10,9,4,1,7,5,
  };
  merge_sort(array);
  PrintArray(array);
}
}  // namespace leetcode
