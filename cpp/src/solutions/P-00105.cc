#include <gtest/gtest.h>
#include <algorithm>
#include "src/include/input.h"
#include "src/include/output.h"
#include "src/include/tree_node.h"

namespace leetcode {
class P00105 : public ::testing::Test {
 protected:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
  }

 private:
  template <typename InputIterator>
  TreeNode* buildTree(InputIterator pre_begin, InputIterator pre_end, InputIterator in_begin,
                      InputIterator in_end) {
    if (pre_begin >= pre_end) return nullptr;
    if (in_begin >= in_end) return nullptr;

    TreeNode* root = new TreeNode(*pre_begin);
    auto inRootPos = std::find(in_begin, in_end, *pre_begin);
    auto leftSize = std::distance(in_begin, inRootPos);

    root->left = buildTree(std::next(pre_begin), std::next(pre_begin, leftSize + 1), in_begin,
                           std::next(in_begin + leftSize));
    root->right =
        buildTree(std::next(pre_begin, leftSize + 1), pre_end, std::next(inRootPos), in_end);

    return root;
  }
};

TEST_F(P00105, Solution) {
  std::vector<std::tuple<std::vector<int>, std::vector<int>>> cases{
      std::make_tuple<std::vector<int>, std::vector<int>>(std::vector<int>{3, 9, 20, 15, 7},
                                                          std::vector<int>{9, 3, 15, 20, 7}),
      std::make_tuple<std::vector<int>, std::vector<int>>(std::vector<int>{-1},
                                                          std::vector<int>{-1}),
  };
}
}  // namespace leetcode
