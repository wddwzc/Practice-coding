/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

    }
};
// @lc code=end



// 递归交换
class Solution {
public:
    void helper(TreeNode *node) {
        if (!node)  return;
        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;
        helper(node->left);
        helper(node->right);
        return;
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};