/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        
    }
};
// @lc code=end




// 动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())  return "";
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int max_len = INT_MIN;
        string max_str;
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i < n; ++i) {
                int j = i + len - 1;
                if (j >= n) break;
                else if (i == j) {
                    dp[i][j] = true;
                }
                else if (i + 1 == j && s[i] == s[j]) {
                    dp[i][j] = true; 
                }
                else {
                    if (i + 1 <= j - 1) {
                        dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                    }
                }
                if (dp[i][j] && max_len < (j - i + 1)) {
                    max_len = j - i + 1;
                    max_str = s.substr(i, max_len);
                }
            }
        }
        return max_str;
    }
};


// 动态规划改进版
class Solution
{
public:
    string longestPalindrome(string s)
    {
        //判断空字符串的情况
        if (s == "")
        {
            return "";
        }
        string result("");
        int sSize = int(s.size());
        vector<bool> store(sSize, false);
        int start = 0, end = 0, maxLen = 0;
        //动态规划 store[i] 从上层向下层循环
        for (int j = 0; j < sSize; j++)
        {
            for (int i = 0; i <= j; i++)
            {
                //长度为1，2的情况单独考虑
                store[i] = (s[i] == s[j] && (j - i < 3 || store[i + 1]));
                if (store[i] && (j - i + 1) > maxLen)
                {
                    maxLen = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }

        result = s.substr(start, end - start + 1);
        return result;
    }
};