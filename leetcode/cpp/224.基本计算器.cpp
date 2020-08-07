/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {

    }
};
// @lc code=end




// 栈 分情况讨论
class Solution {
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        int ans = 0;
        string num = "";
        char pre = ' ';
        for (auto c : s) {
            if (c == ' ')  {
                continue;
            }
            if (isdigit(c)) {
                num = num + c;
            }
            else {
                if (isdigit(pre)) {
                    nums.push(stoi(num));
                    num.clear();
                }
                if (ops.empty()) {
                    ops.push(c);
                }
                else {
                    char op = ops.top();
                    if (c == ')') {
                        while (op != '(') {
                            int num1 = nums.top();
                            nums.pop();
                            int num2 = nums.top();
                            nums.pop();
                            nums.push(calculate(num2, num1, op));
                            ops.pop();
                            op = ops.top();
                        }
                        ops.pop();
                    }
                    else if (c == '+' || c == '-') {
                        if (op == '+' || op == '-') {
                            ops.pop();
                            int num1 = nums.top();
                            nums.pop();
                            int num2 = nums.top();
                            nums.pop();
                            nums.push(calculate(num2, num1, op));
                        }
                        ops.push(c);
                    }
                    else if (c == '(') {
                        ops.push(c);
                    }
                }
            }
            pre = c;
        }
        if (!num.empty()) {
            nums.push(stoi(num));
        }
        while (!ops.empty()) {
            char op = ops.top();
            ops.pop();
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            nums.push(calculate(num2, num1, op));
        }
        return nums.top();
    }

    int calculate(int num1, int num2, char op) {
        int ret;
        if (op == '+') {
            ret = num1 + num2;
        }
        else if (op == '-') {
            ret = num1 - num2;
        }
        return ret;
    }
};