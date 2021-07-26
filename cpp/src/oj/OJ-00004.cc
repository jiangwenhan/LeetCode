#include <iostream>
#include <vector>

int summary(std::vector<int>& array) {
  int sum = 0;
  for (auto item : array) {
    sum += item;
  }
  return sum;
}

void next_combine(int& count, std::vector<int>& array, int index, std::vector<int>& selected, int c, int m) {
  if (selected.size() >= c) {
    if (summary(selected) % m == 0) {
      count++;
    }
    return;
  }

  if (index >= array.size()) return;

  selected.push_back(array[index]);
  next_combine(count, array, index + 1, selected, c, m);
  selected.pop_back();
  next_combine(count, array, index + 1, selected, c, m);
}

int main(int argc, char** argv) {
  int group = 0;
  std::cin >> group;
  while (group-- > 0) {
    int n = 0;
    std::cin >> n;
    int m = 0;
    std::cin >> m;
    std::vector<int> array;
    while (n-- > 0) {
      int tmp = 0;
      std::cin >> tmp;
      array.push_back(tmp);
    }
    int s_count = 0;
    std::vector<int> selected;
    for (int i = 1; i <= array.size(); ++i) {
      next_combine(s_count, array, 0, selected, i, m);
    }
    std::cout << s_count << std::endl;
  }
}
