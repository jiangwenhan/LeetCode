#include "src/include/list_node.h"

#include <gtest/gtest.h>

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
  ListNode* l1 = new ListNode(2);
  ListNode* head1 = l1;
  head1->next = new ListNode(4);
  head1 = head1->next;
  head1->next = new ListNode(3);

  ListNode* l2 = new ListNode(5);
  ListNode* head2 = l2;
  head2->next = new ListNode(6);
  head2 = head2->next;
  head2->next = new ListNode(4);

  auto result = addTwoNumbers(l1, l2);
  while (result != nullptr) {
    std::cout << result->val << " ";
    result = result->next;
  }
  std::cout << std::endl;
}
}  // namespace leetcode
