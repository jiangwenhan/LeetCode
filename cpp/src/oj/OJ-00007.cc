#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  int group = 0;
  std::cin >> group;
  while (group--) {
    int team = 0;
    std::cin >> team;
    int rank = 0;
    std::cin >> rank;
    // input ai
    std::vector<int> A;
    auto load_team = team;
    while (load_team--) {
      int a = 0;
      std::cin >> a;
      A.push_back(a);
    }

    // input bi
    std::vector<int> B;
    load_team = team;
    while (load_team--) {
      int b = 0;
      std::cin >> b;
      B.push_back(b);
    }

    // greedy
    A[0] += B[0];

    int tencent_ac = A[0];

    std::sort(A.begin(), A.end(), std::greater<>());

    bool can_be = false;

    for (int i = 0; i < A.size(); ++i) {
      if (A[i] <= tencent_ac) {
        if (i + 1 <= rank) {
          can_be = true;
          std::cout << "Yes" << std::endl;
          break;
        }
      }
    }

    if (!can_be) {
      std::cout << "No" << std::endl;
    }

  }

  return 0;
}
