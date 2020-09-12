/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {

    }
};
// @lc code=end







// 笔试的时候遇到了，只能处理个位数的情况
class Solution {
public:
    string decodeString(string s) {
        vector<string> stk_str;
        vector<int> stk_num;
        int kh = 0;
        string res;
        string temp;
        for (auto ch : s) {
            if (ch == '[') {
                stk_str.push_back(temp);
                temp.clear();
                kh++;
            }
            else if (ch == ']') {
                if (temp.empty()) {
                    temp = stk_str.back();
                    stk_str.pop_back();
                }
                string st;
                if (!stk_str.empty()) {
                    st = stk_str.back();
                    stk_str.pop_back();
                }
                int n = stk_num.back();
                stk_num.pop_back();
                for (int i = 0; i < n; ++i) {
                    st += temp;
                }
                stk_str.push_back(st);
                temp.clear();
            }
            else if (isdigit(ch)) {
                stk_num.push_back(ch - '0');
            }
            else {
                temp += ch;
            }
        }
        if (!temp.empty())  stk_str.push_back(temp);
        for (auto ele : stk_str) {
            res += ele;
        }
        return res;
    }
};
