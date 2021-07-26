#pragma once

#include <vector>

template <typename T>
void next_combine(std::vector<std::vector<T>>& result, std::vector<T>& array, int index, std::vector<T>& selected, int m) {
  if (selected.size() == m) {
    result.push_back(selected);
    return;
  }

  if (index >= array.size()) return;

  selected.push_back(array[index]);
  next_combine(result, array, index + 1, selected, m);
  selected.pop_back();
  next_combine(result, array, index + 1, selected, m);
}

template <typename T>
std::vector<std::vector<T>> combination(std::vector<T>& array, int m) {
  std::vector<std::vector<T>> result;
  std::vector<T> selected;
  next_combine(result, array, 0, selected, m);
  return result;
}


