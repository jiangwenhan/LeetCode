#pragma once

#include <deque>
#include <iostream>
#include <vector>
#include "src/include/heap.h"
#include "src/include/list_node.h"
#include "src/include/tree_node.h"

void PrintArray(std::vector<int>& array) {
  std::cout << "[";
  for (std::size_t i = 0; i < array.size(); ++i) {
    std::cout << array[i];
    if (i != array.size() - 1) {
      std::cout << ",";
    }
  }
  std::cout << "]" << std::endl;
}

void PrintLinkedList(ListNode* node) {
  while (node != nullptr) {
    std::cout << node->val;
    if (node->next == nullptr) {
      std::cout << std::endl;
    } else {
      std::cout << "->";
    }
    node = node->next;
  }
}

void PrintTree(TreeNode* root) {
  TreeNode* curr = root;
  std::deque<TreeNode*> q;
  q.push_back(curr);
  int level_count = 1;
  int level_hight = 1;
  std::cout << "level " << level_hight << ": ";
  while (q.size() > 0) {
    curr = q.front();
    q.pop_front();
    level_count--;

    if (curr == nullptr) {
      std::cout << "N";
    } else {
      std::cout << curr->val;
      if (curr->left != nullptr) {
        q.push_back(curr->left);
      } else {
        q.push_back(nullptr);
      }

      if (curr->right != nullptr) {
        q.push_back(curr->right);
      } else {
        q.push_back(nullptr);
      }
    }
    std::cout << " ";

    if (level_count == 0) {
      if (q.size() != 0) {
        std::cout << std::endl << "level " << level_hight << ": ";
      } else {
        std::cout << std::endl;
      }
      level_count = q.size();
      level_hight++;
    }
  }
}

void PrintHeap() {}
