#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"
#include <unordered_map>

namespace leetcode {
class LRUCache {
  struct CacheNode {
    int key;
    int value;
    CacheNode* prev;
    CacheNode* next;
  };
 public:
  LRUCache(int capacity) {
    capacity_ = capacity;
    head_ = tail_ = nullptr;
  }

  int get(int key) {
    auto find_iter = node_map_.find(key);
    if (find_iter == node_map_.end()) {
      return -1;
    }
    int value = find_iter->second->value;
    update(find_iter->second);
    return value;
  }

  void put(int key, int value) {
    auto find_iter = node_map_.find(key);
    if (find_iter == node_map_.end()) {
      if (capacity_ == node_map_.size()) {
	retire();
      }
      CacheNode* node = new CacheNode;
      node->key = key;
      node->value = value;
      node->prev = nullptr;
      node->next = head_;
      if (node->next != nullptr) {
	node->next->prev = node;
      }
      head_ = node;
      if (tail_ == nullptr) {
	tail_ = node;
      }
      node_map_[key] = node;
    } else {
      find_iter->second->value = value;
      update(find_iter->second);
    }
  }
 private:
  void retire() {
    if (head_ == tail_) {
      head_ = nullptr;
    }
    auto prev = tail_->prev;
    auto find_iter = node_map_.find(tail_->key);
    if (find_iter != node_map_.end()) {
      node_map_.erase(find_iter);
      delete tail_;
    }
    tail_ = prev;
    if (tail_ != nullptr) {
      tail_->next = nullptr;
    }
  }

  void update(CacheNode* node) {
    if (head_ == node) {
      return;
    }
    
    auto prev = node->prev;
    auto next = node->next;
    if (tail_ == node) {
      tail_ = prev;
    } else {
      // do nothing
    }
    if (prev != nullptr) {
      prev->next = next;
      if (prev->next != nullptr) {
	prev->next->prev = prev;
      }
    }
    node->next = head_;
    node->prev = nullptr;
    if (node->next != nullptr) {
      node->next->prev = node;
    }
    head_ = node;
  }
 private:
  int capacity_;
  std::unordered_map<int, CacheNode*> node_map_;
  CacheNode* head_;
  CacheNode* tail_;
};

class P00146 : public ::testing::Test {
 protected:
  
};

TEST_F(P00146, Solution) {
  // using namespace leetcode;
  LRUCache lRUCache(1);
  lRUCache.put(2, 1);
  std::cout << lRUCache.get(2) << std::endl;    // return 1
  lRUCache.put(3, 2);
  std::cout << lRUCache.get(2) << std::endl;
  std::cout << lRUCache.get(3) << std::endl;
}
}  // namespace leetcode


