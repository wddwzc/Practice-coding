/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {

    }
};
// @lc code=end


// 双指针模拟
class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int len = max(n, m);
        int temp, flag = 0;
        string ans;
        ans.reserve(len + 1);
        for (int i = 0; i < len; ++i) {
            temp = (i < m ? (num1[m - i - 1] - '0') : 0) + (i < n ? (num2[n - i - 1] - '0') : 0) + flag;
            flag = temp / 10;
            temp = temp % 10;
            ans.push_back(temp + '0');
        }
        if (flag) {
            ans.push_back(flag + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};