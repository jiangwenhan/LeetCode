#pragma once

#include <deque>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "src/include/list_node.h"
#include "src/include/tree_node.h"

int SkipSpace(char* input) {
  int distance = 0;
  char* curr = input;
  while (curr != nullptr && curr[0] != '\0') {
    if (std::isspace(curr[0])) {
      distance++;
      curr++;
      continue;
    } else {
      break;
    }
  }
  return distance;
}

int AToArray(std::vector<int>& array, char* input) {
  char* curr = input;
  int buffer_size = 0;
  const std::regex int_regex("\\s*(\\+|-)?[[:digit:]]+\\s*");
  while (curr != nullptr && curr[0] != '\0') {
    if (curr[0] == '[') {
      curr++;
      auto dis = SkipSpace(curr);
      curr += dis;
    } else if (curr[0] == ',' || curr[0] == ']') {
      std::string buffer(curr - buffer_size, buffer_size);
      // check format using regex
      if (!std::regex_match(buffer, int_regex)) return -1;
      try {
        array.emplace_back(std::stoi(buffer));
      } catch (...) {
        return -2;
      }
      curr++;
      buffer_size = 0;
    } else {
      buffer_size++;
      curr++;
    }
  }
  return 0;
}

int AToLinkedList(ListNode* head, char* input) {
  if (head == nullptr) return 0;
  char* curr = input;
  int buffer_size = 0;
  const std::regex int_regex("\\s*(\\+|-)?[[:digit:]]+\\s*");
  while (curr != nullptr && curr[0] != '\0') {
    if (curr[0] == '[') {
      curr++;
      auto dis = SkipSpace(curr);
      curr += dis;
    } else if (curr[0] == ',' || curr[0] == ']') {
      std::string buffer(curr - buffer_size, buffer_size);
      if (!std::regex_match(buffer, int_regex)) return -1;
      try {
        head->val = std::stoi(buffer);
        if (curr[0] == ',') {
          head->next = new ListNode;
          head = head->next;
        }
      } catch (...) {
        return -2;
      }
      curr++;
      buffer_size = 0;
    } else {
      buffer_size++;
      curr++;
    }
  }
  return 0;
}

int AToMatrix(std::vector<std::vector<int>>& matrix, char* input) {
  char* curr = input;
  int buffer_size = 0;
  int dimension = 0;
  while (curr != nullptr && curr[0] != '\0') {
    if (curr[0] == '[') {
      dimension++;
      curr++;
      auto dis = SkipSpace(curr);
      curr += dis;
    } else if (curr[0] == ',' || curr[0] == ']') {
      if (curr[0] == ']') dimension--;
      if (dimension == 1 && curr[0] != ',') {
        std::string buffer(curr - buffer_size - 1, buffer_size + 2);
        std::vector<int> array;
        auto res = AToArray(array, buffer.data());
        if (res != 0) return res;
        matrix.emplace_back(array);
        buffer_size = 0;
      } else if (dimension == 2) {
        buffer_size++;
      }
      curr++;
    } else {
      if (dimension == 2) {
        buffer_size++;
      }
      curr++;
    }
  }
  return 0;
}

int AToBinaryTree(TreeNode* root, char* input) {
  char* curr = input;
  std::deque<TreeNode*> level_nodes;
  int buffer_size = 0;
  const std::regex re_int("\\s*(\\+|-)?[[:digit:]]+\\s*");
  const std::regex re_null("\\s*null\\s*");

  while (curr != nullptr && curr[0] != '\0') {
    if (curr[0] == '[') {
      curr++;
      auto dis = SkipSpace(curr);
      curr += dis;
    } else if (curr[0] == ',' || curr[0] == ']') {
      std::string buffer(curr - buffer_size, buffer_size);
      if (buffer.size() == 0) {
        return 404;
      }
      // std::cout << "buffer:[" << buffer << "], size:" << buffer.size() << std::endl;
      if (std::regex_match(buffer, re_int)) {
        try {
          level_nodes.push_back(new TreeNode(std::stoi(buffer)));
        } catch (...) {
          return -2;
        }
      } else if (std::regex_match(buffer, re_null)) {
        level_nodes.push_back(nullptr);
      } else {
        return -1;
      }
      curr++;
      buffer_size = 0;
    } else {
      buffer_size++;
      curr++;
    }
  }

  std::cout << "[";
  for (auto item : level_nodes) {
    if (item != nullptr) {
      std::cout << item->val << ",";
    } else {
      std::cout << "null,";
    }
  }
  std::cout << "]" << std::endl;

  int count = 1;
  std::deque<TreeNode*> upper_level;
  upper_level.push_back(root);

  if (level_nodes.size() > 0) {
    upper_level.front()->val = level_nodes.front()->val;
    level_nodes.pop_front();
  }

  while (level_nodes.size() > 0) {
    int next_count = 0;
    for (int i = 0; i < count && level_nodes.size() > 0; ++i) {
      TreeNode* top = upper_level.front();
      upper_level.pop_front();

      if (top == nullptr) {
        continue;
      }

      if (level_nodes.size() > 0) {
        TreeNode* left = level_nodes.front();
        level_nodes.pop_front();
        top->left = left;
        upper_level.push_back(left);
        next_count++;
      }

      if (level_nodes.size() > 0) {
        TreeNode* right = level_nodes.front();
        level_nodes.pop_front();
        top->right = right;
        upper_level.push_back(right);
        next_count++;
      }

      if (i == count - 1) {
        count = next_count;
      }
    }
  }

  return 0;
}
