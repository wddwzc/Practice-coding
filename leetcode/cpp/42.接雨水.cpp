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
    // 暴力求解
    int trap(vector<int>& height) {
        int n = height.size();
        int capacity = 0, left, right;
        for (int i = 0; i < n; ++i) {
            
        }
        return capacity;
    }
};
// @lc code=end

class Solution {
public:
    // 单调栈
    int trap(vector<int>& height) {
        int n = height.size();
        int capacity = 0, pre = 0;
        stack<int> h_stack;
        for (int i = 0; i < n; ++i) {
            while (!h_stack.empty() && height[h_stack.top()] <= height[i]) {
                capacity += (i - h_stack.top() - 1);
                h_stack.pop();
            }
            h_stack.push(i);
        }
        return capacity;
    }
};

class Solution {
public:
    // 单调栈
    int trap(vector<int>& height) {
        int n = height.size();
        int capacity = 0, occupy = 0, pre = 0;
        stack<int> h_stack;
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