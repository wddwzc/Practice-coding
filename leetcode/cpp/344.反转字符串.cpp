/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        
    }
};
// @lc code=end


// 反转 好像比reverse效率高
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size(), n2 = n / 2;
        for (int i = 0; i < n2; ++i) {
            swap(s[i], s[n - i - 1]);
        }
        return;
    }
};