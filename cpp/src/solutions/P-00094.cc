#include <gtest/gtest.h>
#include "src/include/output.h"
#include "src/include/tree_node.h"

namespace leetcode {
class P00094 : public ::testing::Test {
 protected:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> res;
    dfs(res, root);
    return res;
  }

 private:
  void dfs(std::vector<int>& res, TreeNode* node) {
    if (node == nullptr) {
      return;
    }
    dfs(res, node->left);
    res.emplace_back(node->val);
    dfs(res, node->right);
  }
};

TEST_F(P00094, Solution) {
  // case 1
  TreeNode c1_3(3);
  TreeNode c1_2(2, &c1_3, nullptr);
  TreeNode c1_root(1, nullptr, &c1_2);
  auto res1 = inorderTraversal(&c1_root);
  PrintArray(res1);

  // case 2
  auto res2 = inorderTraversal(nullptr);
  PrintArray(res2);

  // case 3
  TreeNode c3_root(1, nullptr, nullptr);
  auto res3 = inorderTraversal(&c3_root);
  PrintArray(res3);
}
}  // namespace leetcode
