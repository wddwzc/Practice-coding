/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {

    }
};
// @lc code=end



// 数学方法
class Solution {
public:
    int integerBreak(int n) {
        int result = 1;
        if (n == 2) {
            result = 1;
        }
        else if (n == 3) {
            result = 2; 
        }
        else if (n > 3) {
            int count = n / 3;
            int remain = n % 3;
            if (remain == 1) {
                --count;
                result *= 4;
            }
            else if (remain == 2) {
                --count;
                result *= 6;
            }
            for (int i = 0; i < count; ++i) {
                result *= 3;
            }
        }
        return result;
    }
};


// 动态规划
class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        vector <int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = max(max(2 * (i - 2), 2 * dp[i - 2]),
                        max(3 * (i - 3), 3 * dp[i - 3]));
        }
        return dp[n];
    }
};