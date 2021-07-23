#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"
#include "src/include/list_node.h"

namespace leetcode {
class P00083 : public ::testing::Test {
 protected:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* curr = head;
    ListNode* next = curr->next;
    while (curr != nullptr && curr->next != nullptr) {
      if (curr->val == next->val) {
        curr->next = next->next;
      } else {
        curr = next;
      }
      next = next->next;
    }
    return head;
  }
};

TEST_F(P00083, Solution) {
  std::vector<std::string> cases{
    "[1,1,2]",
    "[1,1,2,3,3]",
  };

  for (auto each : cases) {
    ListNode head;
    auto res = AToLinkedList(&head, each.data());
    std::cout << "res:" << res << std::endl;
    if (res == 0) {
      PrintLinkedList(deleteDuplicates(&head));
    }
  }
}
}  // namespace leetcode
