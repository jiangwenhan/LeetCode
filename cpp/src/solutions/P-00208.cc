#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

class Trie {
  constexpr static int ALPHABET_SIZE = 26;
  struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    ~TrieNode() {
      for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (children[i] != nullptr) {
          delete children[i];
          children[i] = nullptr;
        }
      }
    }
  };
 public:
  /** Initialize your data structure here. */
  Trie() {
    root_.isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
      root_.children[i] = nullptr;
    }
  }

  /** Inserts a word into the trie. */
  void insert(std::string word) {
    struct TrieNode* pCrawl = &root_;
    for (int i = 0; i < word.size(); ++i) {
      int index = word[i] - 'a';
      if (pCrawl->children[index] == nullptr) {
        pCrawl->children[index] = getNode();
      }
      pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
  }

  /** Returns if the word is in the trie. */
  bool search(std::string word) {
    struct TrieNode* pCrawl = &root_;
    for (int i = 0; i < word.size(); ++i) {
      int index = word[i] - 'a';
      if (pCrawl->children[index] == nullptr) {
        return false;
      }
      pCrawl = pCrawl->children[index];
    }
    return pCrawl->isEndOfWord;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(std::string prefix) {
    struct TrieNode* pCrawl = &root_;
    for (int i = 0; i < prefix.size(); ++i) {
      int index = prefix[i] - 'a';
      if (pCrawl->children[index] == nullptr) {
        return false;
      }
      pCrawl = pCrawl->children[index];
    }
    return true;
  }
 private:
  TrieNode* getNode() {
    struct TrieNode* node = new TrieNode;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
      node->children[i] = nullptr;
    }
    node->isEndOfWord = false;
    return node;
  }
 private:
  struct TrieNode root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

namespace leetcode {
class P00208 : public ::testing::Test {
 protected:
};

TEST_F(P00208, Solution) {
}
}  // namespace leetcode
