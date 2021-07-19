#include <gtest/gtest.h>
#include <deque>
#include "src/include/output.h"
#include "src/include/tree_node.h"
namespace leetcode {
class P00102 : public ::testing::Test {
 protected:
  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> res;
    if (root == nullptr) return res;
    int level_size = 1;
    std::deque<TreeNode*> level_nodes;
    level_nodes.push_back(root);
    res.emplace_back(std::vector<int>{});

    while (level_nodes.size() > 0) {
      TreeNode* curr = level_nodes.front();
      level_nodes.pop_front();
      res[res.size() - 1].emplace_back(curr->val);

      --level_size;

      if (curr->left != nullptr) {
        level_nodes.push_back(curr->left);
      }
      if (curr->right != nullptr) {
        level_nodes.push_back(curr->right);
      }

      if (level_size == 0) {
        level_size = level_nodes.size();
        if (level_size > 0) {
          res.emplace_back(std::vector<int>{});
        }
      }
    }

    return res;
  }
};

TEST_F(P00102, Solution) {
  // case 1
  TreeNode c1_15(15, nullptr, nullptr);
  TreeNode c1_7(7, nullptr, nullptr);
  TreeNode c1_20(20, &c1_15, &c1_7);
  TreeNode c1_9(9, nullptr, nullptr);
  TreeNode c1_root(3, &c1_9, &c1_20);

  auto res1 = levelOrder(&c1_root);
  for (auto& each : res1) {
    PrintArray(each);
  }
  // case 2
  TreeNode c2_root(1, nullptr, nullptr);
  auto res2 = levelOrder(&c2_root);
  for (auto& each : res2) {
    PrintArray(each);
  }
  // case 3
  auto res3 = levelOrder(nullptr);
  std::cout << res3.size() << std::endl;
}
}  // namespace leetcode
