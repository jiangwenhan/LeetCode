#pragma once
#include <algorithm>
#include <vector>

template <typename T>
void selection_sort(std::vector<T>& array) {
  for (int i = 0; i < array.size(); ++i) {
    int ith = i;
    for (int j = i + 1; j < array.size(); ++j) {
      if (array[j] < array[ith]) {
	ith = j;
      }
    }
    std::swap(array[i], array[ith]);
  }
}

template <typename T>
void bubble_sort(std::vector<T>& array) {
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 0; i < array.size() - 1; ++i) {
      if (array[i] > array[i + 1]) {
	flag = true;
	std::swap(array[i], array[i + 1]);
      }
    }
  }
}

template <typename T>
void insertion_sort(std::vector<T>& array) {
  for (int i = 1; i < array.size(); ++i) {
    auto key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

template <typename T>
void counting_sort(std::vector<T>& array) {
  // TODO
}

template <typename T>
void radix_sort(std::vector<T>& array) {
  // TODO
}

template <typename T>
int partition(std::vector<T>& array, int p, int r) {
  auto pivot = array[r];
  int i = p - 1;
  for (int j = p; j < r; ++j) {
    if (array[j] <= pivot) {
      std::swap(array[++i], array[j]);
    }
  }
  if (i + 1 != r) {
    std::swap(array[i + 1], array[r]);
  }
  return i + 1;
}

template <typename T>
void quick_sort(std::vector<T>& array, int p, int r) {
  if (p < r) {
    int q = partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
  }
}

template <typename T>
void quick_sort(std::vector<T>& array) {
  quick_sort(array, 0, array.size() - 1);
}

void merge(std::vector<int>& array, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  std::vector<int> L(n1 + 1, INT_MAX);
  std::vector<int> R(n2 + 1, INT_MAX);
  for (int i = 0; i < n1; ++i) {
    L[i] = array[p + i];
  }
  for (int i = 0; i < n2; ++i) {
    R[i] = array[q + i + 1];
  }
  int i = 0, j = 0;
  for (int k = 0; k <= r; ++k) {
    if (L[i] <= R[j]) {
      array[k] = L[i++];
    } else {
      array[k] = R[j++];
    }
  }
}

void merge_sort(std::vector<int>& array, int p, int r) {
  if (p < r) {
    int q = p + (r - p) >> 1;
    merge_sort(array, p, q);
    merge_sort(array, q + 1, r);
    merge(array, p, q, r);
  }
}

void merge_sort(std::vector<int>& array) {
  merge_sort(array, 0, array.size() - 1);
}










