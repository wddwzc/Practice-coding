/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {

    }
};
// @lc code=end



// 暴力检索
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        string match;
        match += s[0];
        for (int i = 1; i <= len / 2; ++i) {
            if (s[i] == match[0]) {
                if (len % match.size() == 0) {
                    int skip = match.size(), n = len / match.size();
                    bool flag = true;
                    for (int pos = 1; pos < n; ++pos) {
                        if (s.substr(pos * skip, skip) != match) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)  return true;
                }
            }
            match += s[i];
        }
        return false;
    }
};