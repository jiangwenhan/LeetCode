#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"
#include "src/include/list_node.h"

namespace leetcode {
class P00160 : public ::testing::Test {
 protected:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode* a = headA;
    ListNode* b = headB;
    while (a != b) {
      if (a != nullptr) {
	a = a->next;
      } else {
	a = headB;
      }

      if (b != nullptr) {
	b = b->next;
      } else {
	b = headA;
      }
    }
    return a;
  }
};

TEST_F(P00160, Solution) {
  {
    // case 1: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
    ListNode intersect(8);
    ListNode headA(4);
    ListNode* cur = &headA;
    ListNode A1(1);
    cur->next = &A1, cur = cur->next;
    cur->next = &intersect, cur = cur->next;
    ListNode A2(4);
    cur->next = &A2, cur = cur->next;
    ListNode A3(5);
    cur->next = &A3, cur = cur->next;

    ListNode headB(5);
    cur = &headB;
    ListNode B1(6);
    cur->next = &B1, cur = cur->next;
    ListNode B2(1);
    cur->next = &B2, cur = cur->next;
    cur->next = &intersect, cur = cur->next;
    ListNode B3(4);
    cur->next = &B3, cur = cur->next;
    ListNode B4(5);
    cur->next = &B4, cur = cur->next;

    ListNode* res = getIntersectionNode(&headA, &headB);
    if (nullptr != res) {
      std::cout << res->val << std::endl;
    }
  }
}
}  // namespace leetcode
