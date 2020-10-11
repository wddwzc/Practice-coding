/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {

    }
};
// @lc code=end



// dfs  通过hash_value去重
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        len = nums.size();
        vector<int> cur_list;
        for (int i = 0; i < len; ++i)
            dfs(nums, cur_list, i);
        return res;
    }

    void dfs(vector<int> &nums, vector<int> &cur, int pos) {
        cur.push_back(nums[pos]);
        if (!cur.empty() && cur.size() >= 2) {
            int hash_val = getHash(cur);
            if (visited.find(hash_val) == visited.end()) {
                res.push_back(cur);
                visited.insert(hash_val);
            }
        }
        for (int i = pos + 1; i < len; ++i) {
            if (nums[i] >= cur.back()) {
                dfs(nums, cur, i);
            }
        }
        cur.pop_back();
        return;
    }

    int getHash(vector<int> &number) {
        int base = 263, mod = int(1E9) + 7;
        int hashValue = 0;
        for (const auto &x: number) {
            hashValue = 1LL * hashValue * base % mod + (x + 101);
            hashValue %= mod;
        }
        return hashValue;
    }

    int len;
    unordered_set<int> visited;
    vector<vector<int>> res;
};


// 递归枚举 + 减枝
class Solution {
public:
    void dfs(int cur, int last, vector<int>& nums) {
        if (cur == nums.size()) {
            if (temp.size() >= 2) {
                ans.push_back(temp);
            }
            return;
        }
        if (nums[cur] >= last) {
            temp.push_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            temp.pop_back();
        }
        if (nums[cur] != last) {
            dfs(cur + 1, last, nums);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, INT_MIN, nums);
        return ans;
    }

    vector<int> temp; 
    vector<vector<int>> ans;
};