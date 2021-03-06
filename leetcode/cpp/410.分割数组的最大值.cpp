/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {

    }
};
// @lc code=end



// 二分搜索  最小的最大值，范围是max_num---sum
// 在这个范围内二分搜索，每次计算分成的组数，和m比较
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long long sum_val = 0, max_val = 0;
        for (auto num : nums) {
            sum_val += num;
            max_val = max(max_val, (long long)num);
        }
        long long left = max_val, right = sum_val;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long count = 1, temp = 0;
            for (auto num : nums) {
                temp += num;
                if (temp > mid) {
                    temp = num;
                    ++count;
                }
            }
            if (count == m) {
                right = mid;
            }
            else if (count < m) {
                right = mid;
            }
            else if (count > m) {
                left = mid + 1;
            }
        }
        return left;
    }
};


// 动态规划
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long> pre_sum(n + 1);
        pre_sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            pre_sum[i] += pre_sum[i - 1];
        }
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, m); ++j) {
                for (int k = 0; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], pre_sum[i] - pre_sum[k]));
                }
            }
        }
        return dp[n][m];
    }
};