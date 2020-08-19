/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
    }
};
// @lc code=end







class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *node = head;
        int len = 0;
        while (node) {
            node = node->next;
            ++len;
        }
        return helper(head, len);
    }

    TreeNode* helper(ListNode* head, int length) {
        if (length == 1)  return new TreeNode(head->val);
        if (length == 0)  return nullptr;
        int mid = length / 2;
        int i = 1;
        ListNode* node = head;
        while (i <= mid) {
            node = node->next;
            ++i;
        }
        TreeNode *tree = new TreeNode(node->val);
        tree->left = helper(head, mid);
        tree->right = helper(node->next, length - i);
        return tree;
    }
};


