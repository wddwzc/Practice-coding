/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted, counts(n);
        for (int i = n - 1; i >= 0; --i) {
            int ind = binarySearch(sorted, nums[i]);
            counts[i] = ind;
            sorted.insert(sorted.begin() + ind, nums[i]);
        }
        return counts;
    }

    int binarySearch(vector<int> &arr, int target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                right = mid;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            } 
            else if (arr[mid] > target) {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end


// 暴力方法超时


// 二分查找   倒序遍历，构建有序序列
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted, counts(n);
        for (int i = n - 1; i >= 0; --i) {
            int ind = binarySearch(sorted, nums[i]);
            counts[i] = ind;
            sorted.insert(sorted.begin() + ind, nums[i]);
        }
        return counts;
    }

    int binarySearch(vector<int> &arr, int target) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                right = mid;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            } 
            else if (arr[mid] > target) {
                right = mid;
            }
        }
        return left;
    }
};