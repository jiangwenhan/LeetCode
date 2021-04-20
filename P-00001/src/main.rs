/*
  Example 1:
   Input: nums = [2,7,11,15], target = 9
   Output: [0,1]
   Output: Because nums[0] + nums[1] == 9, we return [0, 1].
  Example 2:
   Input: nums = [3,2,4], target = 6
   Output: [1,2]
  Example 3:
   Input: nums = [3,3], target = 6
   Output: [0,1]

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/two-sum
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let result: Vec<i32> = Vec::new();
        for i in 0..nums.len() {
            for j in 1..2 {
                if i == j {
                    continue;
                }
                if target == nums[i] + nums[j] {
                    println!("{} {}", i, j);
                }
            }
        }
        result
    }
}

fn main() {
    let nums = vec![3, 3];
    let target = 6;
    Solution::two_sum(nums, target);
}
