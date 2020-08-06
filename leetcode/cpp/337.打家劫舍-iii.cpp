/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {

    }
};
// @lc code=end


// 动态规划 不用记忆
class Solution {
public:
    int rob(TreeNode* root) {
        if (!root)  return 0;
        vector<int> res = dp(root);
        return max(res[0], res[1]);
    }
    vector<int> dp(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }
        vector<int> left = dp(node->left);
        vector<int> right = dp(node->right);
        // 如果当前节点抢，子节点就不能抢， val + 孙子节点最大之和
        int rob = node->val + left[0] + right[0];
        // 如果当前节点不抢，就没有限制，所以应该考虑子节点所有情况，取最大的
        // 比如 3-4-8 3是当前节点，8是孙子，也是叶子节点
        // 这时候4的最优抢法，就是不抢4，抢8；这就导致no_rob可能要大于rob
        int no_rob = max(left[1], left[0]) + max(right[1], right[0]);
        return {no_rob, rob};
    }
};


// 动态规划 不用记忆 相比上边，vector改成了数组，空间时间能好一些
class Solution {
public:
    
    int rob(TreeNode* root) {
        if (!root)  return 0;
        int *res = dp(root);
        return max(res[0], res[1]);
    }
    int* dp(TreeNode* node) {
        if (!node) {
            return new int[]{0,0};
        }
        int* left = dp(node->left);
        int* right = dp(node->right);
        int rob = node->val + left[0] + right[0];
        int no_rob = max(left[0], left[1]) + max(right[0], right[1]);
        return new int[]{no_rob, rob};
    }
};


// dfs
class Solution {
public:
    int rob(TreeNode* root) {
        if (!root)  return 0;
        return dfs(root);
    }
    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        if (memo.count(node)) {
            return memo[node];
        }
        int rob = node->val;
        // 如果当前节点抢，就是 val + 孙子节点最大之和
        rob += node->left == nullptr ? 0 : dfs(node->left->left) + dfs(node->left->right);
        rob += node->right == nullptr ? 0 : dfs(node->right->left) + dfs(node->right->right);
        // 如果当前节点不抢，就是 子节点最大之和
        int no_rob = dfs(node->left) + dfs(node->right);
        rob = max(rob, no_rob);
        memo[node] = rob;
        return rob;
    }
    unordered_map<TreeNode*, int> memo;
};