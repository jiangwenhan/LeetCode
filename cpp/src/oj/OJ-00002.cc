#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int statistics(std::vector<int>& array, int n) {
  int l = 0, r = array.size();
  int result = 0;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (array[mid] <= n) {
      l = mid + 1;
      result = std::max(result, mid + 1);
    } else {
      r = mid;
    }
  }
  return result;
}

int main(int argc, char** argv) {
  int array_size = 0, line = 0;
  std::cin >> array_size;

  std::vector<int> array;
  while (array_size--) {
    std::string s;
    std::cin >> s;
    array.push_back(std::atoi(s.data()));
  }

  std::sort(array.begin(), array.end());

  std::cin >> line;

  while (line-- > 0) {
    int n = 0;
    std::cin >> n;
    std::cout << statistics(array, n) << std::endl;
  }
  return 0;
}
