/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    }
};
// @lc code=end



// 拓扑排序 BFS
// 写的比较麻烦
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree;
        stack<int> q;
        int count = 0;
        // 构建临接表  另外还要记录入度
        for (auto pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
            graph[pre[1]];
            inDegree[pre[0]];
            inDegree[pre[1]]++;
        }
        // 找到入度为0的，入栈
        for (auto degree : inDegree) {
            if (degree.second == 0) {
                q.push(degree.first);
            }
        }
        // BFS
        while (!q.empty()) {
            int n = q.size();
            count += n;
            for (int i = 0; i < n; ++i) {
                int ind = q.top();
                q.pop();
                for (int j = 0; j < graph[ind].size(); ++j) {
                    int ind_link = graph[ind][j];
                    --inDegree[ind_link];
                    if (inDegree[ind_link] == 0) {
                        q.push(ind_link);
                    }
                }
            }
        }
        // 最后可上课程数是否等于课程总数
        if (count < graph.size()) {
            return false;
        }
        return true;
    }
};

// BFS  入度表（参考拓扑排序）
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        deque<int> q;
        int count = 0;
        // 构建临接表  另外还要记录入度
        for (auto pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
            inDegree[pre[1]]++;
        }
        // 找到入度为0的，入队
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push_back(i);
            }
        }
        // BFS
        while (!q.empty()) {
            int n = q.size();
            count += n;
            for (int i = 0; i < n; ++i) {
                int ind = q.front();
                q.pop_front();
                for (int j = 0; j < graph[ind].size(); ++j) {
                    int ind_link = graph[ind][j];
                    --inDegree[ind_link];
                    if (inDegree[ind_link] == 0) {
                        q.push_back(ind_link);
                    }
                }
            }
        }
        // 最后可上课程数是否等于课程总数
        if (count < numCourses) {
            return false;
        }
        return true;
    }
};


// 官方题解
// DFS 检测有向图中的环
class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};