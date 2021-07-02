#include "src/include/list_node.h"

#include <gtest/gtest.h>

namespace leetcode {
class P00003 : public ::testing::Test {
 protected:
  int lengthOfLongestSubstring(std::string s) {
    if (s.size() == 0) return 0;
    std::set<char> unrepeated;
    size_t lpos = 0, rpos = 0, max_length = 0;
    for (; rpos < s.size();) {
      if (!unrepeated.contains(s.at(rpos))) {
        unrepeated.emplace(s.at(rpos));
        ++rpos;
      } else {
        while (lpos < rpos && unrepeated.contains(s.at(rpos))) {
          unrepeated.erase(s.at(lpos));
          ++lpos;
        }
        unrepeated.emplace(s.at(rpos));
        ++rpos;
      }
      // std::cout << unrepeated.size() << std::endl;
      max_length = std::max(max_length, unrepeated.size());
    }
    return max_length;
  }
};

TEST_F(P00003, Solution) {
  std::vector<std::string> cases{"abcabcbb", "bbbbb", "pwwkew", ""};

  for (auto& each : cases) {
    std::cout << lengthOfLongestSubstring(each) << std::endl;
  }
}
}  // namespace leetcode
