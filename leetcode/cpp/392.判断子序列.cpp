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