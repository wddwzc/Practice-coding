/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// 迭代BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)  return nullptr;
        unordered_map<Node*, Node*> visited;
        stack<Node*> node_stack;
        node_stack.push(node);
        visited.insert(make_pair(node, new Node(node->val)));
        Node *cur_node = nullptr;
        while (!node_stack.empty()) {
            int n = node_stack.size();
            for (int i = 0; i < n; ++i) {
                cur_node = node_stack.top();
                node_stack.pop();
                for (auto neighbor : cur_node->neighbors) {
                    if (visited.count(neighbor) == 0) {
                        visited.insert(make_pair(neighbor, new Node(neighbor->val)));
                        node_stack.push(neighbor);
                    }
                    visited[cur_node]->neighbors.push_back(visited[neighbor]);
                }
            }
        }
        return visited[node];
    }
};
// @lc code=end


// 迭代BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)  return nullptr;
        unordered_map<Node*, Node*> visited;
        stack<Node*> node_stack;
        node_stack.push(node);
        visited.insert(make_pair(node, new Node(node->val)));
        Node *cur_node = nullptr;
        while (!node_stack.empty()) {
            int n = node_stack.size();
            for (int i = 0; i < n; ++i) {
                cur_node = node_stack.top();
                node_stack.pop();
                for (auto neighbor : cur_node->neighbors) {
                    if (visited.count(neighbor) == 0) {
                        visited.insert(make_pair(neighbor, new Node(neighbor->val)));
                        node_stack.push(neighbor);
                    }
                    visited[cur_node]->neighbors.push_back(visited[neighbor]);
                }
            }
        }
        return visited[node];
    }
};

// 递归DFS   hashmap记录visited
// hashmap存<node*, new node*>更优
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)  return nullptr;
        if (visited.count(node->val))  return visited[node->val];
        Node *cur_node = new Node(node->val, node->neighbors);
        visited.insert(make_pair(cur_node->val, cur_node));
        for (int i = 0; i < node->neighbors.size(); ++i) {
            cur_node->neighbors[i] = cloneGraph(node->neighbors[i]);
        }
        return cur_node;
    }
    unordered_map<int, Node*> visited;
};



// 递归DFS  每日一题做的，基本上相同
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)  return nullptr;
        if (visited.count(node->val))  return visited[node->val];
        Node *new_node = new Node(node->val);
        visited[new_node->val] = new_node;
        for (auto neighbor : node->neighbors) {
            new_node->neighbors.push_back(cloneGraph(neighbor));
        }
        return new_node;
    }
    unordered_map<int, Node*> visited;
};