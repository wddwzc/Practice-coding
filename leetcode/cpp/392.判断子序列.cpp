/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {

    }
};
// @lc code=end



// 双指针
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty())  return true;
        int len1 = s.length(), len2 = t.length();
        int ind = 0;
        for (auto c : t) {
            if (s[ind] == c) {
                ++ind;
            }
            if (ind == len1) {
                return true;
            }
        }
        return false;
    }
};


// 最长公共子序列 dp 速度比较慢
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty())  return true;
        int len1 = s.length(), len2 = t.length();
        // dp[i][j] t中前j个，与s中前i个 匹配的数量
        // dp降维
        vector<int> dp(len2 + 1);
        int last = 0;
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                int temp = dp[j];
                // 如果相等，dp[i][j] = dp[i - 1][j - 1] + 1
                // 这里用一个中间变量记录
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = last + 1;
                }
                // 如果不等，dp[i][j] = dp[i][j - 1]
                else {
                    dp[j] = dp[j - 1];
                }
                last = temp;
            }
        }
        return dp[len2] == len1;
    }
};