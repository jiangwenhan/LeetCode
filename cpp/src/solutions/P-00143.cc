#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"
#include "src/include/list_node.h"

namespace leetcode {
class P00143 : public ::testing::Test {
 protected:
  void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return;
    ListNode* p1x = head;
    ListNode* p2x = head;
    ListNode* tail = nullptr;
    ListNode* half = nullptr;
    while (p1x != nullptr && p2x != nullptr) {
      if (p2x->next == nullptr) {
        half = p1x->next;
        p1x->next = nullptr;
        break;
      } else if (p2x->next->next == nullptr) {
        half = p1x->next;
        p1x->next = nullptr;
        break;
      } else {
        p2x = p2x->next->next;
        p1x = p1x->next;
      }
    }

    tail = reverse(half);
    ListNode* pl1x = head;
    ListNode* pr1x = tail;
    ListNode dummy_head;
    ListNode* curr = &dummy_head;
    while (pl1x != nullptr || pr1x != nullptr) {
      curr->next = pl1x;
      curr = curr->next;
      if (pl1x != nullptr) {
        ListNode* pl1x_next = pl1x->next;
        curr->next = pr1x;
        curr = curr->next;
        pl1x = pl1x_next;
      }
      if (pr1x != nullptr) {
        pr1x = pr1x->next;
      }
    }
  }

 private:
  ListNode* reverse(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* behind = nullptr;
    while (head != nullptr) {
      ListNode* next = head->next;
      head->next = behind;
      behind = head;
      head = next;
    }
    return behind;
  }
};

TEST_F(P00143, Solution) {
  std::vector<std::string> cases {
    "[1,2,3,4]",
    "[1,2,3,4,5]",
  };

  for (auto each : cases) {
    ListNode head;
    auto res = AToLinkedList(&head, each.data());
    if (res == 0) {
      reorderList(&head);
      PrintLinkedList(&head);
    }
  }
}
}  // namespace leetcode
