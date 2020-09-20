/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
    }
};
// @lc code=end


// 递归枚举+回溯
class Solution {
public:
    void helper(vector<int> &nums, vector<int> &cur, int ind) {
        if (ind < nums.size()) {
            helper(nums, cur, ind + 1);
            cur.push_back(nums[ind]);
            helper(nums, cur, ind + 1);
            cur.pop_back();
        }
        else {
            res.push_back(cur);
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)  return {{}};
        vector<int> cur_set;
        helper(nums, cur_set, 0);
        return res;
    }
    vector<vector<int>> res;
};