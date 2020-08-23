/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {

    }
};
// @lc code=end






// 很麻烦的方法，全排列所有情况，计算对应数值 与 24比较
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<bool> visited(4, false);
        helper(nums, visited, "", 0);
        return flag;
    }

    bool flag = false;

    bool helper(vector<int>& nums, vector<bool> visited, string cur, int count) {
        if (flag)  return true;
        if (count == 4) {
            flag = calculate(cur.substr(0, 7));
        }
        else {
            for (int i = 0; i < 4; ++i) {
                if (!visited[i]) {
                    visited[i] = true;
                    helper(nums, visited, cur + (char)('0' + nums[i]) + "*", count + 1);
                    helper(nums, visited, cur + (char)('0' + nums[i]) + "/", count + 1);
                    helper(nums, visited, cur + (char)('0' + nums[i]) + "+", count + 1);
                    helper(nums, visited, cur + (char)('0' + nums[i]) + "-", count + 1);
                    visited[i] = false;
                }
            }
        }
        return true;
    }

    // 六种情况
    bool calculate(string cur) {
        //cout << cur << endl;
        float n1 = cur[0] - '0';
        float n2 = cur[2] - '0';
        float n3 = cur[4] - '0';
        float n4 = cur[6] - '0';
        char op1 = cur[1], op2 = cur[3], op3 = cur[5];
        // cout << n1 << op1 << n2 << op2 << n3 << op3 << n4 << endl;
        float num;
        num = getResult(getResult(getResult(n1, n2, op1), n3, op2), n4, op3);
        if (fabs(num - 24.0) < 0.00001)  return true;
        num = getResult(getResult(n1, n2, op1), getResult(n3, n4, op3), op2);
        if (fabs(num - 24.0) < 0.00001)  return true;
        num = getResult(getResult(n1, getResult(n2, n3, op2), op1), n4, op3);
        if (fabs(num - 24.0) < 0.00001)  return true;
        num = getResult(n1, getResult(getResult(n2, n3, op2), n4, op3), op1);
        if (fabs(num - 24.0) < 0.00001)  return true;
        num = getResult(n1, getResult(n2, getResult(n3, n4, op3), op2), op1);
        if (fabs(num - 24.0) < 0.00001)  return true;
        return false;
    }

    float getResult(float a, float b, char op) {
        if (op == '/' && b == 0)  return 1000.0;
        switch (op) {
            case '+':   return (a+b);
            case '-':   return (a-b);
            case '*':   return (a*b);
            case '/':   return (a/b);
        }
        return 0.0;
    }
};