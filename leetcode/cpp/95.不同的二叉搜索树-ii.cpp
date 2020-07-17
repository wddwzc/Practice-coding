/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
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
// 递归实现
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0)  return res;
        res = generateTrees_helper(1, n);
        return res;
    }
    vector<TreeNode*> generateTrees_helper(int lo, int hi) {
        vector<TreeNode*> sub_trees;
        if (lo == hi) {
            sub_trees.push_back(new TreeNode(lo));
        }
        else if (lo > hi) {
            sub_trees.push_back(nullptr);
        }
        else {
            for (int i = lo; i <= hi; ++i) {
                vector<TreeNode*> left_trees = generateTrees_helper(lo, i - 1);
                vector<TreeNode*> right_trees = generateTrees_helper(i + 1, hi);
                for (int m = 0; m < left_trees.size(); ++m) {
                    for (int n = 0; n < right_trees.size(); ++n) {
                        TreeNode* new_node = new TreeNode(i);
                        new_node->left = left_trees[m];
                        new_node->right = right_trees[n];
                        sub_trees.push_back(new_node);
                    }
                }
            }
        }
        return sub_trees;
    }
};
// @lc code=end


// 递归实现
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0)  return res;
        res = generateTrees_helper(1, n);
        return res;
    }
    vector<TreeNode*> generateTrees_helper(int lo, int hi) {
        vector<TreeNode*> sub_trees;
        if (lo == hi) {
            sub_trees.push_back(new TreeNode(lo));
        }
        else if (lo > hi) {
            sub_trees.push_back(nullptr);
        }
        else {
            for (int i = lo; i <= hi; ++i) {
                vector<TreeNode*> left_trees = generateTrees_helper(lo, i - 1);
                vector<TreeNode*> right_trees = generateTrees_helper(i + 1, hi);
                for (int m = 0; m < left_trees.size(); ++m) {
                    for (int n = 0; n < right_trees.size(); ++n) {
                        TreeNode* new_node = new TreeNode(i);
                        new_node->left = left_trees[m];
                        new_node->right = right_trees[n];
                        sub_trees.push_back(new_node);
                    }
                }
            }
        }
        return sub_trees;
    }
};