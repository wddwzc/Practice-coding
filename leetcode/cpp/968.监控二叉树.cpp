/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int minCameraCover(TreeNode* root) {

    }
};
// @lc code=end




// 自底向上考虑
// 一个节点有两种情况：
// 有相机：则最佳策略是子节点都没有
// 没相机：最佳策略是，只有其中一个子节点有相机
// 按照这样的方法递归
class Solution {
public:
    vector<int> dfs(TreeNode *node) {
        if (!node)  return {INT_MAX / 2, 0, 0}; 
        vector<int> ls = dfs(node->left);
        vector<int> rs = dfs(node->right);

        // 当前节点有相机
        int a = ls[2] + rs[2] + 1;
        // max(有相机，没相机 0+子节点只有一个有相机)
        int b = min(a, min(ls[0] + rs[1], rs[0] + ls[1]));
        // 当前节点没相机
        int c = min(a, ls[1] + rs[1]);
        return {a, b, c};
    }

    int minCameraCover(TreeNode* root) {
        vector<int> res = dfs(root);
        return res[1];
    }
};
