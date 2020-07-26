/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict{};
        for (auto word : wordDict) {
            dict.insert(word);
        }
        int n = s.length();
        bool *dp = new bool[n + 1];
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dict.find(s.substr(0, i)) != dict.end();
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        bool result = dp[n];
        delete[] dp;
        return result;
    }
};
// @lc code=end



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict{};
        for (auto word : wordDict) {
            dict.insert(word);
        }
        int n = s.length();
        bool *dp = new bool[n + 1];
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dict.find(s.substr(0, i)) != dict.end();
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        bool result = dp[n];
        delete[] dp;
        return result;
    }
};