#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"
#include "src/include/list_node.h"

namespace leetcode {
class P00082 : public ::testing::Test {
 protected:
  ListNode* deleteDuplicates(ListNode* head) {
    return head;
  }
};

TEST_F(P00082, Solution) {
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
