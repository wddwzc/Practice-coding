/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
// 动态规划
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
// @lc code=end

// 数学方法  卡塔兰数字
class Solution {
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};


// 动态规划
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};


// 记忆化递归  普通递归超市
class Solution {
public:
    int numTrees(int n) {
        return numTrees_helper(1, n);
    }

    int numTrees_helper(int lo, int hi) {
        if (lo >= hi) {
            return 1;
        }
        int count = 0, left, right, ind;
        for (int i = lo; i <= hi; ++i) {
            ind = (i - 1) * 100 + lo;
            if (subTree.count(ind)) {
                left = subTree[ind];
            }
            else {
                left = numTrees_helper(lo, i - 1);
                subTree[ind] = left;
            }

            ind = hi * 100 + i + 1;
            if (subTree.count(ind)) {
                right = subTree[ind];
            }
            else {
                right = numTrees_helper(i + 1, hi);
                subTree[ind] = right;
            }

            count += left * right;
        }
        return count;
    }
    unordered_map<int, int> subTree;
};
