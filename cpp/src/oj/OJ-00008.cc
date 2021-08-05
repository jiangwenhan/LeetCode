#include <vector>
#include <iostream>

int main() {
  int player_cnt = 17, target = 3;
  std::vector<int> rounds{
    1,1,3,2,1,
  };
  
  bool has_diff = false;
  int max_repeat = 1;
  int cur_repeat = 1;
  bool repeat = false;
  int max_repeat_end_round = 0;
  int curid = rounds[0];
  int i = 1;
  for (; i < rounds.size();) {
    if (max_repeat >= target) {
      break;
    }
    if (curid == rounds[i]) {
      cur_repeat++;
      if (cur_repeat > max_repeat) {
        max_repeat = cur_repeat;
        max_repeat_end_round = repeat ? rounds.size() + i + 1 : i + 1;
      }
    } else {
      has_diff = true;
      cur_repeat = 1;
      curid = rounds[i];
    }
    if (i == rounds.size() - 1 && !repeat) {
      i = 0;
      repeat = true;
    } else {
      ++i;
    }
  }

  if (!has_diff) {
    max_repeat_end_round = target;
  }

  if (max_repeat < target) {
    std::cout << "INF" << std::endl;
  } else {
    std::cout << max_repeat_end_round << " " << curid << std::endl;
  }

  return 0;
}
