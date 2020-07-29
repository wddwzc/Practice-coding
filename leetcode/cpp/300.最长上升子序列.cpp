/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

    }
};
// @lc code=end


// 二分
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_list;
        for (auto num : nums) {
            if (sorted_list.empty() || num > sorted_list.back()) {
                sorted_list.push_back(num);
                continue;
            }
            int left = 0, right = sorted_list.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (num == sorted_list[mid]) {
                    right = mid;
                }
                else if (num < sorted_list[mid]) {
                    right = mid;
                }
                else if (num > sorted_list[mid]) {
                    left = mid + 1;
                }
            }
            sorted_list[right] = num;
        }
        return sorted_list.size();
    }
};


// 二分 题解
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) d[++len] = nums[i];
            else{
                int l = 1, r = len, pos = 0;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};

// 动态规划
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};