/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    // 
    int trap(vector<int>& height) {
        int n = height.size();
        int capacity = 0, occupy = 0, pre = 0;
        for (int i = 1; i < n; ++i) {
            if (height[pre] <= height[i]) {
                capacity += height[pre] * (i - pre - 1) - occupy;
                pre = i;
                occupy = 0;
            }
            else {
                occupy += height[i];
            }
        }
        return capacity;
    }
};
// @lc code=end
