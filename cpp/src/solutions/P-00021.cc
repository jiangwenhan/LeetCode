#include "src/include/list_node.h"

#include <gtest/gtest.h>

namespace leetcode {
class P00021 : public ::testing::Test {
 protected:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) return nullptr;
    ListNode* dummy_head = new ListNode;
    ListNode* tail = dummy_head;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    if (l1 == nullptr) {
      tail->next = l2;
    } else if (l2 == nullptr) {
      tail->next = l1;
    }
    return dummy_head->next;
  }
};

TEST_F(P00021, Solution) {
  std::vector<std::tuple<ListNode*, ListNode*>> cases = {
      std::tuple<ListNode*, ListNode*>{CreateListNode(std::vector<int>{1, 2, 4})->next,
                                       CreateListNode(std::vector<int>{1, 3, 4})->next},
      std::tuple<ListNode*, ListNode*>{nullptr, nullptr},
      std::tuple<ListNode*, ListNode*>{nullptr, CreateListNode(std::vector<int>{1})->next},
  };

  for (auto& lists : cases) {
    auto result = mergeTwoLists(std::get<0>(lists), std::get<1>(lists));
    while (result != nullptr) {
      std::cout << result->val << " ";
      result = result->next;
    }
    std::cout << std::endl;
  }
}
}  // namespace leetcode
