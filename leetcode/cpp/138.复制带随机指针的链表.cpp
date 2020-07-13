/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// DFS
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)  return nullptr;
        if (visited.count(head))  return visited[head];
        Node *new_node = new Node(head->val);
        visited.insert({head, new_node});
        new_node->next = copyRandomList(head->next);
        new_node->random = copyRandomList(head->random);
        return new_node;
    }
    unordered_map<Node*, Node*> visited;
};
// @lc code=end


// 类比图的DFS
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)  return nullptr;
        if (visited.count(head))  return visited[head];
        Node *new_node = new Node(head->val);
        visited.insert({head, new_node});
        new_node->next = copyRandomList(head->next);
        new_node->random = copyRandomList(head->random);
        return new_node;
    }
    unordered_map<Node*, Node*> visited;
};