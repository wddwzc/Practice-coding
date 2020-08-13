/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

// @lc code=start
class Solution {
public:
    Solution(vector<int>& nums) {

    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {

    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end




// 分析洗牌算法正确性的准则，产生的结果必须有 n! 种可能
// 正确性衡量标准是：对于每种可能的结果出现的概率必须相等，也就是说要足够随机。
// 
class Solution {
public:
    Solution(vector<int>& nums) {
        data = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret = data;
        int n = data.size();
        for (int i = 0; i < n - 1; ++i) {
            swap(ret[i], ret[rand() % (n - i) + i]);
        }
        return ret;
    }

    vector<int> data;
};