#include <gtest/gtest.h>
#include "src/include/output.h"
#include "src/include/tree_node.h"

namespace leetcode {
class P00145 : public ::testing::Test {
 protected:
  std::vector<int> postorderTraversal(TreeNode* root) {
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
    dfs(res, node->right);
    res.emplace_back(node->val);
  }
};

TEST_F(P00145, Solution) {
  // case 1
  TreeNode c1_3(3);
  TreeNode c1_2(2, &c1_3, nullptr);
  TreeNode c1_root(1, nullptr, &c1_2);
  auto res1 = postorderTraversal(&c1_root);
  PrintArray(res1);

  // case 2
  auto res2 = postorderTraversal(nullptr);
  PrintArray(res2);

  // case 3
  TreeNode c3_root(1, nullptr, nullptr);
  auto res3 = postorderTraversal(&c3_root);
  PrintArray(res3);
}
}  // namespace leetcode
