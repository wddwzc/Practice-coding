/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {

    }
};
// @lc code=end




// KMP  src为reverse_s，target为s
// KMP可以得到 从s其实位置可以匹配几个
class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        if (len == 0)  return "";
        string r_s = string(s.rbegin(), s.rend());
        
        vector<int> next(len);
        int j = 0, k = -1;
        next[0] = -1;
        while(j < len - 1) {
            if(k == -1 || s[j] == s[k]) {
                if(s[++j] == s[++k]) {
                    next[j] = next[k];
                }
                else {
                    next[j] = k;
                }
            }
            else {
                k = next[k];
            }
        }

        int i = 0;
        j = 0;
        while(i < len && j < len) {
            if(j == -1 || r_s[i] == s[j]) {
                i++;
                j++;
            }
            else {
                j = next[j];
            }
        }
        return r_s.substr(0, len - j) + s;
    }
};