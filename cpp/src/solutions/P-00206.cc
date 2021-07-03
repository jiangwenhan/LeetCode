#include "src/include/list_node.h"

#include <gtest/gtest.h>

namespace leetcode {
class P00206 : public ::testing::Test {
 protected:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head != nullptr) {
      ListNode* next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};

TEST_F(P00206, Solution) {
  std::vector<ListNode*> cases = {
      CreateListNode(std::vector<int>{1, 2, 3, 4, 5})->next,
      CreateListNode(std::vector<int>{1, 2})->next,
      nullptr,
  };

  for (auto each : cases) {
    auto result = reverseList(each);
    while (result != nullptr) {
      std::cout << result->val << " ";
      result = result->next;
    }
    std::cout << std::endl;
  }
}
}  // namespace leetcode
