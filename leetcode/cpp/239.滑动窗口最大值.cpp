/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
// 单调递减队列
class MonoQue {
public:
    void push(int n) {
        while (!data.empty() && data.back() < n) {
            data.pop_back();
        }
        data.push_back(n);
    }
    int max() {
        return data.front();
    }
    void pop(int n) {
        if (!data.empty() && data.front() == n) {
            data.pop_front();
        }
    }

private:
    deque<int> data;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        MonoQue mono_que;
        for (int i = 0; i < n; ++i) {
            if (i < k - 1) {
                mono_que.push(nums[i]);
            }
            else {
                mono_que.push(nums[i]);
                res.push_back(mono_que.max());
                mono_que.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};
// @lc code=end

