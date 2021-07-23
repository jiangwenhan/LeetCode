#include <iostream>

int summary(int n) {
  return (1 + n) * n / 2;
}

int main(int argc, char** argv) {
  int line = 0;
  std::cin >> line;
  while (line-- > 0) {
    int n = 0;
    std::cin >> n;
    std::cout << summary(n) << std::endl;
  }
  return 0;
}
