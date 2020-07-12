/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 快慢指针
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (slow && fast) {
            slow = slow->next;
            if (fast->next) {
                fast = fast->next->next;
            }
            else {
                return false;
            }
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

