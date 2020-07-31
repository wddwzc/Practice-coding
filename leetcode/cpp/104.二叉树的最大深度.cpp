/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        
    }
};
// @lc code=end


// 递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        max_depth = 0;
        DFS(root, 0);
        return max_depth;
    }

    void DFS(TreeNode *node, int depth) {
        if (!node) return;
        ++depth;
        max_depth = max(depth, max_depth);
        if (node->left) {
            DFS(node->left, depth);
        }
        if (node->right) {
            DFS(node->right, depth);
        }
    }

    int max_depth;
};


// 递归（题解）
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};