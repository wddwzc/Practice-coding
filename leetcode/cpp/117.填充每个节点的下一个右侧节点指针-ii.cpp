/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
    }
};
// @lc code=end



class Solution {
public:
    Node* connect(Node* root) {
        if (!root)  return root;
        queue<Node*> que_node;
        que_node.push(root);
        while (!que_node.empty()) {
            int len = que_node.size();
            Node *pre = nullptr;
            for (int i = 0; i < len; ++i) {
                Node *cur_node = que_node.front();
                que_node.pop();
                if (cur_node->left)  que_node.push(cur_node->left);
                if (cur_node->right)  que_node.push(cur_node->right);
                if (pre)  pre->next = cur_node;
                pre = cur_node;
            }
            pre->next = nullptr;
        }
        return root;
    }
};