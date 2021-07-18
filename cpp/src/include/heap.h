#pragma once

#include <vector>

class Heap {
 public:
  enum HEAP {
    MAX_HEAP,
    MIN_HEAP,
  };

  explicit Heap(HEAP heap_type) : heap_type_(heap_type) {}
  int peek();
  int pop();
  void push(int val);
  int size() { return array_.size(); }

 private:
  void heapifyTop();
  void heapifyDown();
  int getParentIndex(int index);
  int getLeftChildIndex(int index);
  int getRightChildIndex(int index);
  bool hasLeftChild(int index);
  bool hasRightChild(int index);

 private:
  HEAP heap_type_;
  std::vector<int> array_;
};

