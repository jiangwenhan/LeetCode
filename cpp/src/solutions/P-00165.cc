#include <gtest/gtest.h>
#include "src/include/input.h"
#include "src/include/output.h"

namespace leetcode {
class P00165 : public ::testing::Test {
 protected:
  int compareVersion(std::string version1, std::string version2) {
    int v1_begin = 0, v2_begin = 0;
    while (true) {
      int dot_pos1 = version1.substr(v1_begin).find('.');
      int dot_pos2 = version2.substr(v2_begin).find('.');
      // std::cout << "dot_pos1:" << dot_pos1 << " dot_pos2:" << dot_pos2 << std::endl;

      int cur_v1 = v1_begin >= version1.size() ? 0 : std::stoi(version1.substr(v1_begin, dot_pos1));
      int cur_v2 = v2_begin >= version2.size() ? 0 : std::stoi(version2.substr(v2_begin, dot_pos2));

      // std::cout << "v1:" << cur_v1 << " v2:" << cur_v2 << std::endl;
      if (cur_v1 == cur_v2) {
        v1_begin = (dot_pos1 == std::string::npos ? version1.size() : v1_begin + dot_pos1 + 1);
	v2_begin = (dot_pos2 == std::string::npos ? version2.size() : v2_begin + dot_pos2 + 1);
      } else {
	return cur_v1 > cur_v2 ? 1 : -1;
      }
      // std::cout << "v1_begin:" << v1_begin << " v2_begin:" << v2_begin << std::endl;


      if (dot_pos1 == std::string::npos && dot_pos2 == std::string::npos) {
	break;
      }
    }

    // std::cout << "v1_size:" << version1.size() << " v2_size:" << version2.size() << std::endl;
    // std::cout << "v1_begin:" << v1_begin << " v2_begin:" << v2_begin << std::endl;

    return 0;
  }
};

TEST_F(P00165, Solution) {
  std::cout << compareVersion("1.01", "1.001") << std::endl;
  std::cout << compareVersion("1.0", "1.0.0") << std::endl;
  std::cout << compareVersion("0.1", "1.1") << std::endl;
  std::cout << compareVersion("1.0.1", "1") << std::endl;
  std::cout << compareVersion("7.5.2.4", "7.5.3") << std::endl;
}
}  // namespace leetcode
