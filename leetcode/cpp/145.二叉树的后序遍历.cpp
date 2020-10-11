/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        
    }
};
// @lc code=end


// 迭代后序遍历
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack_node;
        if(root != nullptr)  stack_node.push(root);
        while(!stack_node.empty()){
            TreeNode *node = stack_node.top();
            stack_node.pop();
            if(node!=nullptr){
                stack_node.push(node);  //在左节点之前重新插入该节点，以便在左节点之后处理（访问值）
                stack_node.push(nullptr); //nullptr跟随node插入，标识已经访问过，还没有被处理
                if(node->right)  stack_node.push(node->right);
                if(node->left)  stack_node.push(node->left);
            }else{
                res.push_back(stack_node.top()->val);
                stack_node.pop();
            }
        }
        return res;
    }
};


// 递归后序遍历
class Solution {
public:
    // 递归
    vector<int> postorderTraversal(TreeNode* root) {
        postorder_helper(root);
        return res;
    }

    void postorder_helper(TreeNode *node) {
        if (!node)  return;
        postorder_helper(node->left);
        postorder_helper(node->right);
        res.push_back(node->val);
        return;
    }
    vector<int> res;
};