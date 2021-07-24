#include <gtest/gtest.h>
#include <deque>
#include "src/include/input.h"
#include "src/include/list_node.h"
#include "src/include/output.h"

namespace leetcode {
class P00082 : public ::testing::Test {
 protected:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return head;
    std::deque<ListNode*> stack;
    stack.push_front(head);
    ListNode* curr = head->next;
    bool pop_top = false;
    while (curr != nullptr) {
      ListNode* top = stack.front();
      if (top->val == curr->val) {
        pop_top = true;
      } else {
        if (pop_top) {
          stack.pop_front();
        }
        if (stack.size() != 0) {
          stack.front()->next = curr;
        }
        stack.push_front(curr);
        pop_top = false;
      }
      curr = curr->next;
    }

    if (pop_top) {
      stack.pop_front();
    }

    if (stack.size() != 0) {
        stack.front()->next = nullptr;
    } else {
      return nullptr;
    }

    return stack.back();
  }
};

TEST_F(P00082, Solution) {
  std::vector<std::string> cases{
      // "[1,1,2]",
      // "[1,1,2,3,3]",
      // "[1,2,3,3,4,4,5]",
      // "[1,1,1,2,3]",
      "[1,1]",
  };

  for (auto each : cases) {
    ListNode head;
    auto res = AToLinkedList(&head, each.data());
    std::cout << "res:" << res << std::endl;
    if (res == 0) {
      auto result = deleteDuplicates(&head);
      if (result != nullptr) {
        PrintLinkedList(result);
      }
    }
  }
}
}  // namespace leetcode
