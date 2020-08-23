/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

    }
};
// @lc code=end





// 根据 start 排序，然后合并
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n < 2)  return intervals;
        sort(intervals.begin(), intervals.end(),
            [](const vector<int> &a, const vector<int> &b) { return  a[0] < b[0]; });
        
        vector<vector<int>> res;
        vector<int> cur = intervals[0];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= cur[1]) {
                cur[1] = max(intervals[i][1], cur[1]);
            }
            else {
                res.push_back(cur);
                cur = intervals[i];
            }
        }
        res.push_back(cur);
        return res;
    }
};