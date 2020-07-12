/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    // 单调栈
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        stack<int> mono;
        for (int i = 0; i < n; ++i) {
            while (!mono.empty() && T[mono.top()] < T[i]) {
                res[mono.top()] = i - mono.top();
                mono.pop();
            }
            mono.push(i);
        }
        return res;
    }
};

// @lc code=end


class Solution {
public:
    // 从后往前遍历  利用历史信息剪枝
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            int j = i + 1;
            while (j < n) {
                if (T[j] > T[i]) {
                    // 如果找到了就停止循环，记录index
                    res[i] = j - i;
                    break;
                }
                else if (res[j] == 0) {
                    // 此时T[j]<=T[i]，如果对应res为0，那当前res也应该为0
                    break;
                }
                else {
                     // 此时T[j]<=T[i]，如果res不为0，则利用该值跳跃
                    j += res[j];
                }
            }
            
        }
        return res;
    }
};
