#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"
#include "src/include/tree_node.h"

namespace leetcode {
class P00124 : public ::testing::Test {
 protected:
  int maxPathSum(TreeNode* root) {
    max_sum = INT_MIN;
    dfs(root);
    return max_sum;
  }
 private:
  int max_sum;
  int dfs(TreeNode* node) {
    if (node == nullptr) return 0;
    int l = dfs(node->left);
    int r = dfs(node->right);
    int sum = node->val;
    if (l > 0) sum += l;
    if (r > 0) sum += r;
    max_sum = std::max(max_sum, sum);
    return std::max(l, r) > 0 ? std::max(l, r) + node->val : node->val;
  }
};

TEST_F(P00124, Solution) {
  std::vector<std::string> cases{
    "[1,2,3]",
    "[-10,9,20,null,null,15,7]",
  };

  for (auto each : cases) {
    TreeNode root;
    auto res = AToBinaryTree(&root, each.data());
    std::cout << "res:" << res << std::endl;
    if (res == 0) {
      PrintTree(&root);
      std::cout << maxPathSum(&root) << std::endl;
    }
  }
}
}  // namespace leetcode
