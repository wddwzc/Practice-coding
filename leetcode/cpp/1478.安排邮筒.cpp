/*
 * @lc app=leetcode.cn id=1478 lang=cpp
 *
 * [1478] 安排邮筒
 */

// @lc code=start
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {

    }
};
// @lc code=end


// 动态规划
class Solution {
public:
    int minDistance(vector<int>& houses, int K) {
        sort(houses.begin(), houses.end());
        int n = houses.size();
        vector<vector<int>> rec(n, vector<int>(n, 0));
        // 先计算在第i和第j个房子间放邮筒，最小距离总和
        for(int i = 0; i < n; i ++){
            for(int j = i; j < n; j ++){
                int mid = i + j >> 1;
                for(int k = i; k <= j; k ++){
                    rec[i][j] += abs(houses[k] - houses[mid]);
                }
            }
        }
        // dpij 表示i个数，j个邮筒，最小划分方法
        // 枚举ij对应的所有情况
        // 最大值负责区间，前j-1个邮箱各负责一个房子，第j个负责j-1到i的所有
        // 最小区间，第j个邮箱负责第i个房子
        vector<vector<int>> dp(n, vector<int>(K + 1, 2e9));
        for(int i = 0; i < n; i ++) dp[i][1] = rec[0][i];
        for(int i = 0; i < n; i ++) {
            for(int j = 2; j <= min(i + 1, K); j ++) {
                for(int k = j - 1; k <= i; k ++) {
                    dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + rec[k][i]);
                }
            }
        }
        return dp[n-1][K];
    }
};