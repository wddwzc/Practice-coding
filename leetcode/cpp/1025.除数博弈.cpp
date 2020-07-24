/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */

// @lc code=start

class Solution {
public:
    bool divisorGame(int N) {
        
    }
};
// @lc code=end



// 数学方法（归纳法）
class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};

// 递推
// dp存的是对应N先手胜负情况
// 遍历所有情况，是否能让bob下一状态是必败的
class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N + 1, false);
        if (N == 1)  return false;
        if (N == 2)  return true;
        dp[1] = false;
        dp[2] = true;
        for (int i = 3; i <= N; ++i) {
            for (int j = 1; j < i; ++j) {
                if (i % j == 0 && !dp[i - j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};