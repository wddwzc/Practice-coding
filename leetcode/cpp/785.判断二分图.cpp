/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
// 迭代DFS  数据里会有多个图
// 并查集
class UFS
{
public:
    UFS() {  }
    UFS(int n) {
        for (int i = 0; i < n; ++i) {
            p.push_back(i);
            rank.push_back(0);
        }
    }
    int find_root(int x) {
        if (p[x] != x) {
            p[x] = find_root(p[x]);
        }
        return p[x];
    }
    void union_(int x, int y) {
        int rx = find_root(x);
        int ry = find_root(y);
        if (rank[rx] < rank[ry]) {
            p[rx] = ry;
        }
        else if (rank[rx] > rank[ry]) {
            p[ry] = rx;
        }
        else {
            p[rx] = ry;
            rank[ry] += 1;
        }
    }
    vector<int> p;
    vector<int> rank;
    
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        UFS ufs(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            int root = ufs.find_root(i);
            for (auto neighbor : graph[i]) {
                if (root == ufs.find_root(neighbor)) {
                    return false;
                }
            }
            for (int j = 1; j < graph[i].size(); ++j) {
                ufs.union_(graph[j - 1], graph[j]);
            }
        }
        return true;
    }
};
// @lc code=end

// 迭代DFS  数据里会有多个图
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, int> mark_map;
        stack<int> node_stack;
        int ind, ind_linked;
        for (int j = 0; j < n; ++j) {
            if (mark_map.count(j) == 0) {
                mark_map[j] = 0;
                node_stack.push(j);
            }
            else {
                continue;
            }
            while (!node_stack.empty()) {
                ind = node_stack.top();
                node_stack.pop();
                for (int i = 0; i < graph[ind].size(); ++i) {
                    ind_linked = graph[ind][i];
                    if (mark_map.count(ind_linked) == 0) {
                        mark_map[ind_linked] = mark_map[ind] ^ 1;
                        node_stack.push(ind_linked);
                    }
                    else {
                        if (mark_map[ind_linked] == mark_map[ind]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};


// 并查集
class UFS
{
    void UFS(int n) {
        for (int i = 0; i < n; ++i) {
            p.push_back(i);
            rank.push_back(0);
        }
    }
    int find_root(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
    void union(int x, int y) {
        int rx = find_root(x);
        int ry = find_root(y);
        if (rank[rx] < rank[ry]) {
            p[rx] = ry;
        }
        else if (rank[rx] > rank[ry]) {
            p[ry] = rx;
        }
        else {
            p[rx] = ry;
            rank[ry] += 1;
        }
    }
    vector<int> p;
    vector<int> rank;
    
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        UFS ufs(graph.size());
        for (int i = 0; i < graph.size(); ++i) {
            int root = ufs.find_root(i);
            for (auto neighbor : graph[i]) {
                if (root == ufs.find_root(neighbor)) {|
                    return false;
                }
            }
            for (int j = 0; j < graph[i].size(); ++j) {
                ufs.union(g[j - 1], g[j]);
            }
        }
        return true;
    }
};