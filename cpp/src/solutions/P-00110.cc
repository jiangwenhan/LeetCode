#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"
#include "src/include/tree_node.h"

namespace leetcode {
class P00110 : public ::testing::Test {
 protected:
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    int ldepth = depth(root->left);
    int rdepth = depth(root->right);
    return isBalanced(root->left) && isBalanced(root->right) && std::abs(ldepth - rdepth) <= 1;
  }

 private:
  int depth(TreeNode* root) {
    if (root == nullptr) return 0;
    int ldepth = depth(root->left);
    int rdepth = depth(root->right);
    return std::max(ldepth, rdepth) + 1;
  }
};

TEST_F(P00110, Solution) {
  std::vector<std::string> cases{
    "[3,9,20,null,null,15,7]",
    "[1,2,2,3,3,null,null,4,4]",
    "[]",
  };

  for (auto each : cases) {
    TreeNode root;
    auto res = AToBinaryTree(&root, each.data());
    if (res == 0) {
      std::cout << std::boolalpha << isBalanced(&root) << std::endl;
    }
  }
  std::cout << "nullptr check: ";
  std::cout << std::boolalpha << isBalanced(nullptr) << std::endl;
}
}  // namespace leetcode
