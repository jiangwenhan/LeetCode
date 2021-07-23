#include <gtest/gtest.h>
#include "src/include/input.h"

class Input : public ::testing::Test {
 protected:
  void GetMatrix(std::vector<std::vector<int>>& matrix, std::string& input) {}
};

TEST_F(Input, SkipSpace) {
  std::cout << SkipSpace("abc") << std::endl;

  char* input = "   123  ";
  auto dis = SkipSpace(input);
  std::cout << "Skip " << dis << std::endl;
  dis = SkipSpace(input + dis + 3);
  std::cout << "Skip " << dis << std::endl;
}

TEST_F(Input, array) {
  char* input = "[     11 , 21123   , 3]";
  
  std::vector<int> array;
  auto res = AToArray(array, input);
  std::cout << "res:" << res << std::endl;
  if (res == 0) {
    for (auto item : array) {
      std::cout << item << ",";
    }
    std::cout << std::endl;
  }
}

TEST_F(Input, linkedList) {
  char* input = "[     11 , 21123   , 3]";
  ListNode head;
  auto res = AToLinkedList(&head, input);
  std::cout << "res:" << res << std::endl;
  if (res == 0) {
    ListNode* curr = &head;
    while (curr != nullptr) {
      std::cout << curr->val << ",";
      curr = curr->next;
    }
    std::cout << std::endl;
  }
}

TEST_F(Input, matrix) {
  char* input = "[  [  1 , 2,  3 ]   ,  [ 4 ,5,6]   , [7,8,9 ]         ]";
  std::vector<std::vector<int>> matrix;
  auto res = AToMatrix(matrix, input);
  std::cout << "res:" << res << std::endl;
  if (res == 0) {
    for (auto& each : matrix) {
      for (auto item : each) {
        std::cout << item << ",";
      }
      std::cout << std::endl;
    }
  }
}

TEST_F(Input, binary_tree) {
  char* input = "[3,9,20,null,null,15,7]";
  TreeNode root;
  auto res = AToBinaryTree(&root, input);
  std::cout << "res:" << res << std::endl;
}
