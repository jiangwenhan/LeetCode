#pragma once

#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

static ListNode* CreateListNode(const std::vector<int>& node_values) {
  if (node_values.size() == 0) return nullptr;
  ListNode* node_list = new ListNode;
  ListNode* tail = node_list;
  for (auto value : node_values) {
    tail->next = new ListNode(value);
    tail = tail->next;
  }

  return node_list;
}
