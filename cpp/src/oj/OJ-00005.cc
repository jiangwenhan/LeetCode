#include <iostream>

int main(int argc, char** argv) {
  int group = 0;
  std::cin >> group;

  while (group--) {
    int size = 0;
    std::cin >> size;
    uint32_t zero_cnt = 0;
    uint32_t positive_cnt = 0;
    uint32_t negative_cnt = 0;
    while (size--) {
      int item = 0;
      std::cin >> item;
      if (item > 0) {
        if (negative_cnt > 0) {
          --negative_cnt;
        } else {
          ++positive_cnt;
        }
      } else if (item < 0) {
        if (positive_cnt > 0) {
          --positive_cnt;
        } else {
          ++negative_cnt;
        }
      } else {
        ++zero_cnt;
      }
    }

    if (abs((int)positive_cnt - (int)negative_cnt) <= (zero_cnt + 1)) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  }

  return 0;
}
