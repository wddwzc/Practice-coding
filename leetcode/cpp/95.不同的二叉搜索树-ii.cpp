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
// 递归实现  记忆化
class Solution {
public:
    vector<TreeNode*> generateTrees(int st,int ed) {
        // 边界条件
        vector<TreeNode*> ans;
        if(st > ed) return {NULL};
        if(!memo[st][ed].empty()) return memo[st][ed];  //4 记忆化代码
        // 递归代码
        for(int i=st;i<=ed;i++){
            for(auto& l : generateTrees(st,i-1)){
                for(auto& r : generateTrees(i+1,ed)){
                    TreeNode* root = new TreeNode(i,l,r);
                    ans.push_back(root);
                }
            }            
        }
        return memo[st][ed]=ans;        //3 记忆化添加得代码
    }
    vector<TreeNode*> generateTrees(int n) {
        memo.resize(n+1,vector<vector<TreeNode*>>(n+1));    //2 记忆化添加得代码
        if(n == 0) return {};
        return generateTrees(1,n);
    }
    vector<vector<vector<TreeNode*>> > memo;    //1 加上记忆化后果然好多了，可见真的重复计算了好多
};
// @lc code=end


// 递归实现  返回值是
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
        // 第一个if去掉，应该也不影响结果
        if (lo == hi) {
            sub_trees.push_back(new TreeNode(lo));
        }
        else if (lo > hi) {
            sub_trees.push_back(nullptr);
        }
        else {
            for (int i = lo; i <= hi; ++i) {
                // 遍历子树根节点所有可能位置
                // 获取右子树
                vector<TreeNode*> left_trees = generateTrees_helper(lo, i - 1);
                // 获取左子树
                vector<TreeNode*> right_trees = generateTrees_helper(i + 1, hi);
                for (int m = 0; m < left_trees.size(); ++m) {
                    for (int n = 0; n < right_trees.size(); ++n) {
                        // 子树进行两两组合
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