/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
// 动态规划
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        if (len1 == 0 || len2 == 0)  return max(len1, len2);
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        for (int i = 0; i <= len1; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= len2; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
// @lc code=end



// 最长公共子序列  记忆化(无记忆化 超时)
// 直接用m×n数组存历史值也可以
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        return len1 + len2 - 2 * lcs(word1, word2, len1, len2);
    }

    int lcs(string &str1, string &str2, int m, int n) {
        int ind = m + n * 1000;
        if (lens.count(ind)) {
            return lens[ind];
        }
        if (m == 0 || n == 0) {
            return 0;
        }
        int len;
        if (str1[m - 1] == str2[n - 1]) {
            len = lcs(str1, str2, m - 1, n - 1) + 1;
        }
        else {
            len = max(lcs(str1, str2, m - 1, n), lcs(str1, str2, m, n - 1));
        }
        lens[ind] = len;
        return len;
    }
    unordered_map<int, int> lens;
};


// 最长公共子序列  动态规划
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<int> dp(len2 + 1, 0);
        for (int i = 1; i <= len1; ++i) {
            int lt = 0;
            for (int j = 1; j <= len2; ++j) {
                int temp = lt;
                lt = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = temp + 1;
                }
                else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
            }
        }
        return len1 + len2 - 2 * dp[len2];
    }
};


// 动态规划
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        if (len1 == 0 || len2 == 0)  return max(len1, len2);
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        for (int i = 0; i <= len1; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= len2; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};