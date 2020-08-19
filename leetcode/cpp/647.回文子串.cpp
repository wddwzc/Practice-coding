/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {

    }
};
// @lc code=end


// 中心扩展法
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        int count = 0;
        for (int i = 0; i < len; ++i) {
            int left = i, right = i;
            while (left >= 0 && right < len && s[left] == s[right]) {
                ++count;
                --left;
                ++right;
            }
            left = i;
            right = i + 1;
            while (left >= 0 && right < len && s[left] == s[right]) {
                ++count;
                --left;
                ++right;
            }
        }
        return count;
    }
};



// 
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, false));
        int count = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (((i - 1 >= 0 && j + 1 <= i - 1 && dp[i - 1][j + 1]) || j + 1 >= i) && s[i] == s[j]) {
                    ++count;
                    dp[i][j] = true;
                }
            }
        }
        return count;
    }
};

