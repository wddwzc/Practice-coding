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
class Solution{
public:
    // 哈希表查重
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodesSeen;
        while (head != nullptr) {
            if (nodesSeen.count(head)) {
                return true;
            } else {
                nodesSeen.insert(head);
            }
            head = head->next;
        }
        return false;
    }
};
// @lc code=end



class Solution{
public:
    // 哈希表查重
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodesSeen;
        while (head != nullptr) {
            if (nodesSeen.count(head)) {
                return true;
            } else {
                nodesSeen.insert(head);
            }
            head = head->next;
        }
        return false;
    }
};

class Solution {
public:
    // 官方题解 快慢指针
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

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