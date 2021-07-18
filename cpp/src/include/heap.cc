#include "src/include/heap.h"

#include <iostream>
#include <stdexcept>

int Heap::peek() {
  if (array_.empty()) {
    throw std::runtime_error("Heap is empty");
  }
  return array_[0];
}

int Heap::pop() {
  auto top = peek();
  array_[0] = array_[array_.size() - 1];
  array_.pop_back();
  heapifyTop();
  return top;
}

void Heap::push(int val) {
  array_.push_back(val);
  heapifyDown();
  std::cout << "[";
  for (auto item : array_) {
    std::cout << item << ",";
  }
  std::cout << "]" << std::endl;
}

void Heap::heapifyTop() {
  auto index = 0;
  while (true) {
    if (!hasLeftChild(index) && !hasRightChild(index)) {
      return;
    }
    auto swap_index = index;
    auto left_index = getLeftChildIndex(index);
    auto right_index = getRightChildIndex(index);
    if (hasLeftChild(index) && hasRightChild(index)) {
      if (heap_type_ == MAX_HEAP) {
        swap_index = array_[left_index] > array_[right_index] ? left_index : right_index;
        swap_index = array_[swap_index] > array_[index] ? swap_index : index;
      } else {
        swap_index = array_[left_index] < array_[right_index] ? left_index : right_index;
        swap_index = array_[swap_index] < array_[index] ? swap_index : index;
      }
    } else if (!hasLeftChild(index)) {
      if (heap_type_ == MAX_HEAP) {
        swap_index = array_[index] > array_[right_index] ? index : right_index;
      } else {
        swap_index = array_[index] < array_[right_index] ? index : right_index;
      }
    } else if (!hasRightChild(index)) {
      if (heap_type_ == MAX_HEAP) {
        swap_index = array_[index] > array_[left_index] ? index : left_index;
      } else {
        swap_index = array_[index] < array_[left_index] ? index : left_index;
      }
    }
    if (swap_index == index) {
      return;
    }

    auto tmp = array_[index];
    array_[index] = array_[swap_index];
    array_[swap_index] = tmp;

    index = swap_index;
  }
}

void Heap::heapifyDown() {
  auto index = array_.size() - 1;
  while (true) {
    if (index == 0) {
      return;
    }
    auto parent_index = getParentIndex(index);
    auto swap_index = index;
    if (heap_type_ == MAX_HEAP) {
      swap_index = array_[index] > array_[parent_index] ? parent_index : index;
    } else {
      swap_index = array_[index] < array_[parent_index] ? parent_index : index;
    }

    if (swap_index == index) {
      return;
    }

    auto tmp = array_[index];
    array_[index] = array_[swap_index];
    array_[swap_index] = tmp;

    index = swap_index;
  }
}

int Heap::getParentIndex(int index) { return (index - 1) / 2; }

int Heap::getLeftChildIndex(int index) { return (index + 1) * 2 - 1; }

int Heap::getRightChildIndex(int index) { return (index + 1) * 2; }

bool Heap::hasLeftChild(int index) {
  return getLeftChildIndex(index) >= array_.size() ? false : true;
}

bool Heap::hasRightChild(int index) {
  return getRightChildIndex(index) >= array_.size() ? false : true;
}
