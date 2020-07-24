/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {

    }
};
// @lc code=end


// 动态规划
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= len1; ++i) {
            dp[i][0] += s1[i - 1] + dp[i - 1][0];
        }
        for (int i = 1; i <= len2; ++i) {
            dp[0][i] += s2[i - 1] + dp[0][i - 1];
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
                }
            }
        }
        return dp[len1][len2];
    }
};


// 动态规划  一维
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<int> dp(len2 + 1);
        dp[0] = 0;
        for (int i = 1; i <= len2; ++i) {
            dp[i] += s2[i - 1] + dp[i - 1];
        }
        for (int i = 1; i <= len1; ++i) {
            int lt = dp[0];
            dp[0] += s1[i - 1];
            for (int j = 1; j <= len2; ++j) {
                int temp = lt;
                lt = dp[j];
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = temp;
                }
                else {
                    dp[j] = min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[len2];
    }
};