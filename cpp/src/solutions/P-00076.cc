#include <gtest/gtest.h>

namespace leetcode {
class P00076 : public ::testing::Test {
 protected:
  std::string minWindow(std::string s, std::string t) {
    std::vector<int> s_freq(256, 0);
    std::vector<int> t_freq(256, 0);
    for (std::size_t i = 0; i < t.size(); ++i) {
      t_freq[t.at(i)]++;
    }
    // PrintFrequence(t_freq);
    int left = 0, right = -1, count = 0, minw = s.size() + 1;
    int final_left = -1, final_right = -1;
    std::string res = "";
    while (left < s.size()) {
      if (right + 1 < s.size() && count < t.size()) {
        s_freq[s.at(right + 1)]++;
        if (s_freq[s.at(right + 1)] <= t_freq[s.at(right + 1)]) {
          count++;
        }
        right++;
      } else {
        if (right - left + 1 < minw && count == t.size()) {
          minw = right - left + 1;
          final_left = left;
          final_right = right;
        }
        if (s_freq[s.at(left)] == t_freq[s.at(left)]) {
          count--;
        }
        s_freq[s.at(left)]--;
        left++;
      }
    }

    if (final_left != -1) {
      res = s.substr(final_left, minw);
    }
    return res;
  }

 private:
  void PrintFrequence(std::vector<int>& freq) {
    for (std::size_t i = 0; i < freq.size(); ++i) {
      char c = (std::isprint(i) > 0 ? i : '?');
      std::cout << c << ":" << freq[i] << " ";
      if ((i + 1) % 32 == 0) {
        std::cout << std::endl;
      }
    }
  }
};

TEST_F(P00076, Solution) {
  std::vector<std::tuple<std::string, std::string>> cases{
      std::make_tuple<std::string, std::string>("ADOBECODEBANC", "ABC"),
      std::make_tuple<std::string, std::string>("a", "a"),
      std::make_tuple<std::string, std::string>("a", "aa"),
  };

  for (auto& each : cases) {
    std::cout << minWindow(std::get<0>(each), std::get<1>(each)) << std::endl;
  }
}
}  // namespace leetcode
