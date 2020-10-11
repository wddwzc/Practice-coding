/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
    }
};
// @lc code=end


// 双指针，一次遍历，0放前边，2放后边
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        for (int i = 0; i <= right; ++i) {
            while (i <= right && nums[i] == 2) {
                swap(nums[i], nums[right]);
                --right;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                ++left;
            }
        }
        return;
    }
};



// 计数排序，遍历两遍
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(3, 0);
        for (auto &num : nums)  ++counts[num];
        int i = 0;
        for (; i < counts[0]; ++i)  nums[i] = 0;
        for (; i < counts[0] + counts[1]; ++i)  nums[i] = 1;
        for (; i < counts[0] + counts[1] + counts[2]; ++i)  nums[i] = 2;
        return;
    }
};