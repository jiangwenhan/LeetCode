#pragma once

#include <string>

static const int ALPHABET_SIZE = 26;

struct TrieNode {
  struct TrieNode* children[ALPHABET_SIZE];
  bool isEndOfWord;
};

struct TrieNode* getNode() {
  struct TrieNode* node = new TrieNode;
  node->isEndOfWord = false;
  for (int i = 0; i < ALPHABET_SIZE; ++i) {
    node->children[i] = nullptr;
  }
  return node;
}

void insert(struct TrieNode* root, std::string key) {
  struct TrieNode* pCrawl = root;
  for (int i = 0; i < key.size(); ++i) {
    int index = key[i] - 'a';
    if (!pCrawl->children[index]) {
      pCrawl->children[index] = getNode();
    }
    pCrawl = pCrawl->children[index];
  }
  pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode* root, std::string key) {
  struct TrieNode* pCrawl = root;
  for (int i = 0; i < key.size(); ++i) {
    int index = key[i] - 'a';
    if (!pCrawl->children[index]) return false;
    pCrawl = pCrawl->children[index];
  }
  return pCrawl->isEndOfWord;
}
