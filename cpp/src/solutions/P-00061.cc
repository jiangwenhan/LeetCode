#include <gtest/gtest.h>
#include "src/include/list_node.h"
#include "src/include/output.h"

namespace leetcode {
class P00061 : public ::testing::Test {
 protected:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return nullptr;
    ListNode* pivot = head;
    size_t size = 1;
    while (head->next != nullptr) {
      head = head->next;
      ++size;
    }
    ListNode* tail = head;
    tail->next = pivot;
    size_t step = size - k % size;
    while (step-- > 0) {
      pivot = pivot->next;
      tail = tail->next;
    }
    tail->next = nullptr;
    return pivot;
  }
};

TEST_F(P00061, Solution) {
  std::vector<std::tuple<ListNode*, int>> cases{
      std::tuple<ListNode*, int>{CreateListNode(std::vector<int>{1, 2, 3, 4, 5})->next, 2},
      std::tuple<ListNode*, int>{CreateListNode(std::vector<int>{0, 1, 2})->next, 4},
  };
  for (auto& each : cases) {
    PrintLinkedList(rotateRight(std::get<0>(each), std::get<1>(each)));
  }
}
}  // namespace leetcode
