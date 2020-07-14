/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
// 递归+记忆化
class Solution {
    vector<vector<int>> memo;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memo = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        return  dfs(triangle, 0, 0);
    }

    int dfs(vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size()) {
            return 0;
        }
        if (memo[i][j] != INT_MAX) {
            return memo[i][j];
        }
        return memo[i][j] = min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
    }
};
// @lc code=end

class Solution {
    vector<vector<int>> memo;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memo = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        return  dfs(triangle, 0, 0);
    }

    int dfs(vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size()) {
            return 0;
        }
        if (memo[i][j] != INT_MAX) {
            return memo[i][j];
        }
        return memo[i][j] = min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
    }
};

// 动态规划 优化O(n)空间
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())  return 0;
        int n = triangle.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int temp1 = dp[0], temp2 = dp[1];
            for (int j = 0; j < i + 1; ++j) {
                temp1 = temp2;
                temp2 = dp[j + 1];
                dp[j + 1] = min(temp1, temp2) + triangle[i][j];
                if (i == n - 1) {
                    res = min(dp[j + 1], res);
                }
            }
        }
        return res;
    }
};

// 动态规划 O(n^2)空间
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())  return 0;
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        dp[0][1] = 0;
        int res;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                dp[i + 1][j + 1] = min(dp[i][j], dp[i][j + 1]) + triangle[i][j];
                if (i == n - 1) {
                    res = min(dp[i + 1][j + 1], res);
                }
            }
        }
        return res;
    }
};