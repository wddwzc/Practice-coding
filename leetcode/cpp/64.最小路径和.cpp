/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
    }
};
// @lc code=end


// 动态规划
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)  return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= m; ++i) {
            if (i > 1) {
                dp[0] = INT_MAX;
            }
            for (int j = 1; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[n];
    }
};