#pragma once

#include <regex>
#include <sstream>
#include <string>
#include <vector>

int SkipSpace(char* input) {
  int distance = 0;
  char* curr = input;
  while (curr != nullptr) {
    if (curr[0] == '\0') {
      break;
    } else if (std::isspace(curr[0])) {
      distance++;
      curr++;
      continue;
    } else {
      break;
    }
  }
  return distance;
}

int AToArray(std::vector<int>& array, char* input) {
  char* curr = input;
  int buffer_size = 0;
  const std::regex int_regex("(\\+|-)?[[:digit:]]+\\s*");
  while (curr != nullptr && curr[0] != '\0') {
    if (curr[0] == '[') {
      curr++;
      auto dis = SkipSpace(curr);
      curr += dis;
    } else if (curr[0] == ',' || curr[0] == ']') {
      std::string buffer(curr - buffer_size, buffer_size);
      // check format using regex
      if (!std::regex_match(buffer, int_regex)) return -1;
      try {
        array.emplace_back(std::stoi(buffer));
      } catch (...) {
        return -2;
      }
      curr++;
      buffer_size = 0;
    } else {
      buffer_size++;
      curr++;
    }
  }
  return 0;
}

int AToMatrix(std::vector<std::vector<int>>& matrix, char* input) {
  return 0;
}

