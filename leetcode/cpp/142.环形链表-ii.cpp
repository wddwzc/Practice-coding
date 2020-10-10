/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        
    }
};
// @lc code=end


// 快慢指针
// 会有如下关系
// a+(n+1)b+nc=2(a+b) -> a=c+(n−1)(b+c)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;

            // ptr 和 slow 在环的第一个节点相遇
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};




// 哈希表 查重
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> node_set;
        ListNode *node = head;
        int index = 0;
        while (node) {
            if (node_set.find(node) != node_set.end()) {
                return node;
            }
            else {
                node_set.insert(node);
            }
            node = node->next;
        }
        return nullptr;
    }
};