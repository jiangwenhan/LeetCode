/*
  Example 1:
   Input: l1 = [2,4,3], l2 = [5,6,4]
   Output: [7,0,8]
   Explanation: 342 + 465 = 807.

  Example 2:
   Input: l1 = [0], l2 = [0]
   Output: [0]

  Example 3:
   Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
   Output: [8,9,9,9,0,0,0,1]

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/add-two-numbers
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

struct Solution;

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let (mut l1, mut l2) = (l1, l2);
        let mut dummy_head = Some(Box::new(ListNode::new(0)));
        let mut tail = &mut dummy_head;
        let (mut l1_end, mut l2_end, mut overflow) = (false, false, false);
        loop {
            let lhs = match l1 {
                Some(node) => {
                    l1 = node.next;
                    node.val
                }
                None => {
                    l1_end = true;
                    0
                }
            };
            let rhs = match l2 {
                Some(node) => {
                    l2 = node.next;
                    node.val
                }
                None => {
                    l2_end = true;
                    0
                }
            };
            if l1_end && l2_end {
                break dummy_head.unwrap().next;
            }
            let sum = lhs + rhs + if overflow { 1 } else { 0 };
            let sum = if sum >= 10 {
                overflow = true;
                sum - 10
            } else {
                overflow = false;
                sum
            };
            tail.as_mut().unwrap().next = Some(Box::new(ListNode::new(sum)));
            tail = &mut tail.as_mut().unwrap().next;
        }
    }
}

fn main() {
    // let list1: Box<ListNode> = Box::new(ListNode { val: 1, next: None });
    // println!("{:?}", list1);
    let result = Solution::add_two_numbers(None, None);
    println!("{:#?}", result.unwrap());
    println!("Hello, world!");
}
