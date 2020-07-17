/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    // 单调栈找左右边界  常数优化
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ind, max_s = 0;
        // r_border初始化为n
        vector<int> l_border(n), r_border(n, n);
        deque<int> h_que;
        for (int i = 0; i < n; ++i) {
            // 此处<=，如果有连续相同高度，最右侧柱子的区间是对的，只要有一个对就行了，是要求最大 
            while (!h_que.empty() && heights[i] <= heights[h_que.back()]) {
                ind = h_que.back();
                r_border[ind] = i;
                h_que.pop_back();
            }
            l_border[i] = h_que.empty() ? -1 :  h_que.back();
            h_que.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            max_s = max(max_s, heights[i] * (r_border[i] - l_border[i] - 1));
        }
        return max_s;
    }
};
// @lc code=end

// 暴力超时 O(n^2)
// 1 选定某根柱子，确定高度h，向两边扩展，找到最近小于h的柱子，确定宽度
// 2 直接暴力搜索


// 单调栈找左右边界
// 基于暴力法，对边界搜索的改进
class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ind, max_s = 0;
        vector<int> l_border(n), r_border(n);
        deque<int> h_que;
        for (int i = 0; i < n; ++i) {
            while (!h_que.empty() && heights[i] <= heights[h_que.back()]) {
                ind = h_que.back();
                h_que.pop_back();
            }
            if (h_que.empty()) {
                l_border[i] = -1;
            }
            else {
                l_border[i] = h_que.back();
            }
            h_que.push_back(i);
        }
        h_que.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!h_que.empty() && heights[i] <= heights[h_que.back()]) {
                ind = h_que.back();
                h_que.pop_back();
            }
            if (h_que.empty()) {
                r_border[i] = n;
            }
            else {
                r_border[i] = h_que.back();
            }
            h_que.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            max_s = max(max_s, heights[i] * (r_border[i] - l_border[i] - 1));
        }
        return max_s;
    }
};


// 单调栈找左右边界  常数优化
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ind, max_s = 0;
        // r_border初始化为n
        vector<int> l_border(n), r_border(n, n);
        deque<int> h_que;
        for (int i = 0; i < n; ++i) {
            // 此处<=，如果有连续相同高度，最右侧柱子的区间是对的，只要有一个对就行了，是要求最大 
            while (!h_que.empty() && heights[i] <= heights[h_que.back()]) {
                ind = h_que.back();
                r_border[ind] = i;
                h_que.pop_back();
            }
            l_border[i] = h_que.empty() ? -1 :  h_que.back();
            h_que.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            max_s = max(max_s, heights[i] * (r_border[i] - l_border[i] - 1));
        }
        return max_s;
    }
};