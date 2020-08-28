/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

    }
};
// @lc code=end


// 回溯
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> paths;
        len = tickets.size() + 1;
        for (auto &ticket : tickets) {
            paths[ticket[0]][ticket[1]]++;
        }
        vector<string> path = {"JFK"};
        helper(paths, path, "JFK", 1);
        return res;
    }

    void helper(unordered_map<string, map<string, int>> &paths, vector<string> &path, string next, int depth) {
        if (flag)  return;
        if (depth >= len) {
            flag = true;
            res = path;
            return;
        }
        map<string, int> &dests = paths[next];
        for (auto &dest : dests) {
            if (flag) break;
            if (dest.second == 0)  continue;
            dest.second--;
            path.push_back(dest.first);
            helper(paths, path, dest.first, depth + 1);
            path.pop_back();
            dest.second++;
        }
        return;
    }

    bool flag = false;
    int len;
    vector<string> res;
};



// 官方题解：Hierholzer 算法
class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

    vector<string> stk;

    void dfs(const string& curr) {
        while (vec.count(curr) && vec[curr].size() > 0) {
            string tmp = vec[curr].top();
            vec[curr].pop();
            dfs(move(tmp));
        }
        stk.emplace_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& it : tickets) {
            vec[it[0]].emplace(it[1]);
        }
        dfs("JFK");

        reverse(stk.begin(), stk.end());
        return stk;
    }
};