#include <gtest/gtest.h>
#include "src/include/heap.h"

class HeapTest : public ::testing::Test {
 protected:
};

TEST_F(HeapTest, Pop) {
  std::vector<std::vector<int>> cases{
    std::vector<int>{50, 10, 7, 3, 4, 49, 20},
    // std::vector<int>{7, 4, 3},
  };

  for (auto& each : cases) {
    Heap heap(Heap::MAX_HEAP);
    for (auto item : each) {
      heap.push(item);
    }

    int size = heap.size();
    std::cout << "[";
    while (size-- > 0) {
      auto res = heap.pop();
      std::cout << res << ",";
    }
    std::cout << "]" << std::endl;
  }
}

