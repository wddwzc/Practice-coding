/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == ')' && s[i - 1] == '(') {
                dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
            }
            else if (s[i] == ')' && s[i - 1] == ')') {
                if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
// @lc code=end


// 动态规划
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == ')' && s[i - 1] == '(') {
                dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
            }
            else if (s[i] == ')' && s[i - 1] == ')') {
                if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};


// 暴力
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> bracket;
        stack<int> index;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (ch == '(') {
                bracket.push(ch);
                index.push(i); 
            }
            else if (ch == ')') {
                if (!bracket.empty() && bracket.top() == '(') {
                    bracket.pop();
                    index.pop();
                }
                else {
                    bracket.push(ch);
                    index.push(i);
                } 
            }
            else {
                bracket.push(ch);
                index.push(i);
            }
        }
        int a1 = 0, a2 = s.length() - 1, max_len = 0;
        if (index.empty()) {
            max_len = s.length();
        }
        else {
            while (!index.empty()) {
                a1 = index.top();
                index.pop();
                if (max_len < (a2 - a1)) {
                    max_len = a2 - a1;
                }
                a2 = a1 - 1;
            }
            if (max_len < a1) {
                max_len = a1;
            }
        }
        return max_len;
    }
};