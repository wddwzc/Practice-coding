/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
class Solution {
public:
    void flatten(TreeNode* root) {
        
    }
};
// @lc code=end





// 递归
class Solution {
public:
    void flatten(TreeNode* root) {
        flatten_helper(root);
        return;
    }

    void flatten_helper(TreeNode *node) {
        if (!node)  return;
        if (node->left) {
            TreeNode *l_node = node->left;
            TreeNode *r_node = l_node;
            while (r_node->right) {
                r_node = r_node->right;
            }
            r_node->right = node->right;
            node->right = l_node;
            node->left = nullptr;
        }
        flatten_helper(node->right);
    }
};



// 迭代
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *node = root;
        while (node) {
            if (!node->left) {
                node = node->right;
            }
            else {
                TreeNode *r_node = node->left;
                while (r_node->right) {
                    r_node = r_node->right;
                }
                r_node->right = node->right;
                node->right = node->left;
                node->left = nullptr;
                node = node->right;
            }
        }
        return;
    }
};


// 后序遍历 ？？？？
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> toVisit;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;

        while (cur != nullptr || !toVisit.empty()) {
            while (cur != nullptr) {
                toVisit.push(cur);
                cur = cur->right;
            }
            cur = toVisit.top();
            if (cur->left == nullptr || cur->left == pre) {
                toVisit.pop();
                cur->right = pre;
                cur->left = nullptr;
                pre = cur;
                cur = nullptr;
            }
            else {
                cur = cur->left;
            }
        }
        return;
    }
};