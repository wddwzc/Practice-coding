/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {

    }
};
// @lc code=end


// 二叉搜索树，中序遍历是有序的
// 在遍历过程中，更新最小间隔
class Solution {
public:
    void dfs(TreeNode* root, int& pre, int& ans) {
        if (!root)  return;
        dfs(root->left, pre, ans);
        if (pre == -1) {
            pre = root->val;
        } else {
            ans = min(ans, root->val - pre);
            pre = root->val;
        }
        dfs(root->right, pre, ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        dfs(root, pre, ans);
        return ans;
    }
};



// 树转数组，排序，求最小间隔
// 很蠢
class Solution {
public:
    void dfs(TreeNode *node) {
        if (!node)  return;
        data.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        sort(data.begin(), data.end());
        int n = data.size();
        int res = INT_MAX;
        for (int i = 1; i < n; ++i) {
            res = min(abs(data[i - 1] - data[i]), res);
        }
        return res;
    }

    vector<int> data;
};