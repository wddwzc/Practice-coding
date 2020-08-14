/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        
    }
};
// @lc code=end



// 栈
class Solution {
public:
    bool isValid(string s) {
        stack<char> ops;
        for (auto ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                ops.push(ch);
            }
            else {
                if (ops.empty()) {
                    return false;
                }
                else {
                    if (ch == ')' && ops.top() == '(') {
                        ops.pop();
                    }
                    else  if (ch == ']' && ops.top() == '[') {
                        ops.pop();
                    }
                    else if (ch == '}' && ops.top() == '{') {
                        ops.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        if (ops.empty())  return true;
        return false;
    }
};