#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"
#include "src/include/trie_node.h"

namespace leetcode {
class P00139 : public ::testing::Test {
 protected:
  bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    TrieNode* root = getNode();
    for (auto word : wordDict) {
      insert(root, word);
    }

    return wordBreak(s, root);
  }
 private:
  bool wordBreak(std::string s, TrieNode* root) {
    int size = s.size();
    if (size == 0) return true;
    for (int i = 1; i <= size; ++i) {
      if (search(root, s.substr(0, i)) && wordBreak(s.substr(i, size - i), root)) {
	return true;
      }
    }
    return false;
  }
};

TEST_F(P00139, Solution) {
  std::vector<std::tuple<std::string, std::vector<std::string>>> cases{
      std::make_tuple<std::string, std::vector<std::string>>(
          "leetcode", std::vector<std::string>{"leet", "code"}),
      std::make_tuple<std::string, std::vector<std::string>>(
          "applepenapple", std::vector<std::string>{"apple","pen"}),
      std::make_tuple<std::string, std::vector<std::string>>(
          "catsandog", std::vector<std::string>{"cats","dog","sand","and","cat"}),
  };

  for (auto& each : cases) {
    std::cout << std::boolalpha
	      << wordBreak(std::get<0>(each), std::get<1>(each)) << std::endl;
  }
}
}  // namespace leetcode










