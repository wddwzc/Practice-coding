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