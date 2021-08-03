#include <gtest/gtest.h>
#include "src/include/trie_node.h"

class TrieTest : public ::testing::Test {
 protected:
};

TEST_F(TrieTest, InsertAndSearch) {
  std::vector<std::string> keys{
    "the", "a", "there",
    "answer", "any", "by",
    "bye", "their"
  };

  struct TrieNode* root = getNode();
  for (int i = 0; i < keys.size(); ++i) {
    insert(root, keys[i]);
  }

  search(root, "the") ? std::cout << "Yes" : std::cout << "No", std::cout << std::endl;
  search(root, "these") ? std::cout << "Yes" : std::cout << "No", std::cout << std::endl;
}
