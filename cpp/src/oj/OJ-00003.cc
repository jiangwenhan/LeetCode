#include <algorithm>
#include <iostream>
#include <vector>

void ZeroOnePack(std::vector<int>& F, int a, int b, int m) {
  for (int v = m; v >= a; --v) {
    F[v] = std::max(F[v], F[v - a] + b);
  }
}

int max_happiness(std::vector<int>& A, std::vector<int>& B, int m) {
  int max_result = 0;
  std::vector<int> F(m + 1, 0);
  for (int i = 0; i < A.size(); ++i) {
    ZeroOnePack(F, A[i], B[i], m);
  }

  return F[m];
}

int main(int argc, char** argv) {
  int n = 0, m = 0;
  std::cin >> n;
  std::cin >> m;

  std::vector<int> A;
  std::vector<int> B;

  while (n--) {
    int a = 0, b = 0;
    std::cin >> a;
    std::cin >> b;
    A.push_back(a);
    B.push_back(b);
  }

  std::cout << max_happiness(A, B, m) << std::endl;

  return 0;
}
