/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start

// 用双指针改良动态编程
class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            // 左比右小，则r_max有保证，只考虑左边
            if (height[left] < height[right]) {
                // 如果大于等于l_max，则不可能蓄到水，否则就有可能
                height[left] >= left_max ? (left_max = height[left]) : 
                                                ans += (left_max - height[left]);
                ++left;
            }
            // 左大于等于右，则l_max有保证
            else {
                // 如果大于等于r_max，则不可能蓄到水，否则就可能
                height[right] >= right_max ? (right_max = height[right]) : 
                                                    ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};
// @lc code=end


// 暴力改良方案（和官方的动态编程类似）  两边最大高度的较小值减去当前高度的值。
// 时间O(n)  空间O(n)
// 分别求每个位置左右两侧最高柱，然后算每个位置的液柱高度
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l_max = 0, r_max = 0;
        vector<int> lh(n);
        vector<int> rh(n);
        for (int i = 0; i < n; ++i) {
            lh[i] = l_max;
            l_max = max(height[i], l_max);
            rh[n - i - 1] = r_max;
            r_max = max(height[n - 1 - i], r_max);
        }
        int count = 0, H = 0;
        for (int i = 0; i < n; ++i) {
            H = min(lh[i], rh[i]);
            H -= height[i];
            count += H > 0 ? H : 0;
        }
        return count;
    }
};

// 用双指针改良动态编程
int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        // 左比右小，则r_max有保证，只考虑左边
        if (height[left] < height[right]) {
            // 如果大于等于l_max，则不可能蓄到水，否则就有可能
            height[left] >= left_max ? (left_max = height[left]) : 
                                            ans += (left_max - height[left]);
            ++left;
        }
        // 左大于等于右，则l_max有保证
        else {
            // 如果大于等于r_max，则不可能蓄到水，否则就可能
            height[right] >= right_max ? (right_max = height[right]) : 
                                                ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}



// 栈的实现方法
int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    // st维护一个非递增序列
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            // 如果是最后一个，直接跳出
            if (st.empty())
                break;
            // top和current中间间隔
            int distance = current - st.top() - 1;
            // top处可以蓄的适量决于current和top-1的最小值，也就是它两边的最小值
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}