#include <gtest/gtest.h>
#include "src/include/list_node.h"
#include "src/include/output.h"

namespace leetcode {
class P00002 : public ::testing::Test {
 protected:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l3 = new ListNode;
    ListNode* head = l3;
    if (l1 == nullptr && l2 == nullptr) {
      return l3;
    }
    while (l1 != nullptr || l2 != nullptr) {
      if (l1 != nullptr) {
        head->val += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        head->val += l2->val;
        l2 = l2->next;
      }

      if (head->val > 9) {
        head->next = new ListNode(head->val / 10);
        head->val = head->val % 10;
      } else if (l1 != nullptr || l2 != nullptr) {
        head->next = new ListNode();
      }
      head = head->next;
    }
    return l3;
  }
};

TEST_F(P00002, Solution) {
  auto l1 = CreateListNode(std::vector<int>{2, 4, 3});
  auto l2 = CreateListNode(std::vector<int>{5, 6, 4});
  PrintLinkedList(addTwoNumbers(l1->next, l2->next));
}
}  // namespace leetcode
