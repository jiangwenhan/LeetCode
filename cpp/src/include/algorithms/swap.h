#pragma once

#include <vector>
#include <stdexcept>

#include "src/include/list_node.h"
#include "src/include/tree_node.h"

void swap(std::vector<int>& array, int i, int j) {
  if (i < 0 || i >= array.size()) {
    throw std::runtime_error("Invalid Index i");
  }

  if (j < 0 || i >= array.size()) {
    throw std::runtime_error("Invalid Index j");
  }

  auto tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

