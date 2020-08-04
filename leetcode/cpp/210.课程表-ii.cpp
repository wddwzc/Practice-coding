/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

    }
};
// @lc code=end



// BFS 相比课程表I的BFS，稍微精简了以下代码，时间和空间有微小改善
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> ans;
        deque<int> q;
        for (auto &pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push_back(i);
            }
        }
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int ind = q.front();
                q.pop_front();
                ans.push_back(ind);
                for (auto &edge : graph[ind]) {
                    --inDegree[edge];
                    if (inDegree[edge] == 0) {
                        q.push_back(edge);
                    }
                }
            }
        }
        if (ans.size() < numCourses) {
            return {};
        }
        return ans;
    }
};



// DFS
// 需要记录节点三个状态，0未搜索、1搜索中、2完成。
// 由于是DFS，当前节点的前导项肯定都是 1搜索中，如果后继有1搜索中，说明存在环
// ans顺序是从最后的节点开始的，所以需要reverse以下
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        visited.resize(numCourses);
        for (auto &pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }
        // 每次挑选一个「未搜索」的节点，开始进行深度优先搜索
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        // 如果没有环，那么就有拓扑排序
        // 注意下标 0 为栈底，因此需要将数组反序输出
        if (!valid) {
            return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(int vertex) {
        // 节点标记为 [搜索中]
        visited[vertex] = 1;
        for (auto &edge : graph[vertex]) {
            if (visited[edge] == 0) {
                dfs(edge);
                if (!valid)  return;
            }
            else if (visited[edge] == 1) {
                // 找到环直接跳出
                valid = false;
                return;
            }
        }
        // 节点标记为 [搜索完成]
        visited[vertex] = 2;
        // 将节点入栈
        ans.push_back(vertex);
    }

    // 存有向图
    vector<vector<int>> graph;
    // 记录节点状态：0=为搜索，1=搜索中，2=已完成
    vector<int> visited;
    vector<int> ans;
    // 判断能否输出全部（有环则false，无环则true）
    bool valid = true;
};