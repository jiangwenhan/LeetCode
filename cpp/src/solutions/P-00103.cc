#include <gtest/gtest.h>
#include <algorithm>
#include <deque>
#include "src/include/tree_node.h"
#include "src/include/input.h"

namespace leetcode {
class P00103 : public ::testing::Test {
  enum DIRECTION {
    LEFT_2_RIGHT,
    RIGHT_2_LEFT,
  };
 protected:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> res;
    if (root == nullptr) return res;

    std::deque<TreeNode*> level_nodes;
    level_nodes.push_back(root);
    int level_count = 1;
    DIRECTION direct = LEFT_2_RIGHT;
    std::vector<int> level_val;
    while (level_nodes.size() > 0) {
      TreeNode* curr = level_nodes.front();
      level_nodes.pop_front();
      level_val.push_back(curr->val);
      level_count--;

      if (curr->left != nullptr) {
        level_nodes.push_back(curr->left);
      }
      if (curr->right != nullptr) {
        level_nodes.push_back(curr->right);
      }

      if (level_count == 0) {
        switch (direct) {
          case LEFT_2_RIGHT: {
            direct = RIGHT_2_LEFT;
          } break;
          case RIGHT_2_LEFT: {
            std::reverse(level_val.begin(), level_val.end());
            direct = LEFT_2_RIGHT;
          } break;
        }
        res.push_back(level_val);
        level_count = level_nodes.size();
        level_val.clear();
      }

    }

    return res;
  }
};

TEST_F(P00103, Solution) {
  std::vector<std::string> cases {
    "[3,9,20,null,null,15,7]",
    "[1]",
  };

  for (auto each : cases) {
    TreeNode root;
    auto res = AToBinaryTree(&root, each.data());
    std::cout << "res: " << res << std::endl;
    if (res != 0) continue;
    auto result = zigzagLevelOrder(&root);
    for (auto& level : result) {
      std::cout << "[";
      for (auto item : level) {
        std::cout << item << ",";
      }
      std::cout << "]" << std::endl;
    }
  }
}
}  // namespace leetcode
