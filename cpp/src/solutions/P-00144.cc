#include <gtest/gtest.h>
#include "src/include/output.h"
#include "src/include/tree_node.h"

namespace leetcode {
class P00144 : public ::testing::Test {
 protected:
  std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> res;
    dfs(res, root);
    return res;
  }

 private:
  void dfs(std::vector<int>& res, TreeNode* node) {
    if (node == nullptr) {
      return;
    }
    res.emplace_back(node->val);
    dfs(res, node->left);
    dfs(res, node->right);
  }
};

TEST_F(P00144, Solution) {
  // case 1
  TreeNode c1_3(3);
  TreeNode c1_2(2, &c1_3, nullptr);
  TreeNode c1_root(1, nullptr, &c1_2);
  auto res1 = preorderTraversal(&c1_root);
  PrintArray(res1);

  // case 2
  auto res2 = preorderTraversal(nullptr);
  PrintArray(res2);

  // case 3
  TreeNode c3_root(1, nullptr, nullptr);
  auto res3 = preorderTraversal(&c3_root);
  PrintArray(res3);
}
}  // namespace leetcode
