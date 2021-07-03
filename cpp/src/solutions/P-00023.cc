#include "src/include/list_node.h"

#include <gtest/gtest.h>

namespace leetcode {
class P00023 : public ::testing::Test {
 protected:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) { return nullptr; }
};

TEST_F(P00023, Solution) {
  auto l1 = CreateListNode(std::vector<int>{1, 4, 5});
  auto l2 = CreateListNode(std::vector<int>{1, 3, 4});
  auto l3 = CreateListNode(std::vector<int>{2, 6});

  std::vector<ListNode*> case1{l1, l2, l3};
  auto result = mergeKLists(case1);
}
}  // namespace leetcode
