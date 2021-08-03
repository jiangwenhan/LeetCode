#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"
#include "src/include/tree_node.h"

namespace leetcode {
class P00128 : public ::testing::Test {
 protected:
  int longestConsecutive(std::vector<int>& nums) {
    int longest = 0;
    std::map<int, int> seq_length_map;
    for (auto item : nums) {
      if (seq_length_map.find(item) != seq_length_map.end())
	continue;

      int l_len = 0, r_len = 0;
      auto find_l_iter = seq_length_map.find(item - 1);
      if (find_l_iter == seq_length_map.end()) {
	l_len = 0;
      } else {
	l_len = find_l_iter->second;
      }
      auto find_r_iter = seq_length_map.find(item + 1);
      if (find_r_iter == seq_length_map.end()) {
	r_len = 0;
      }
      else {
	r_len = find_r_iter->second;
      }
      seq_length_map[item] = l_len + 1 + r_len;
      longest = std::max(longest, seq_length_map[item]);
      seq_length_map[item - l_len] = seq_length_map[item];
      seq_length_map[item + r_len] = seq_length_map[item];
    }
    return longest;
  }
};

TEST_F(P00128, Solution) {
  std::vector<std::string> cases{
    "[100,4,200,1,3,2]",
    "[0,3,7,2,5,8,4,6,0,1]",
  };

  for (auto each : cases) {
    std::vector<int> array;
    auto res = AToArray(array, each.data());
    std::cout << "res:" << res << std::endl;
    if (res == 0) {
      std::cout << longestConsecutive(array) << std::endl;
    }
  }
}
}  // namespace leetcode
