/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    // 排序后 匹配
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int p1 = 0, p2 = 0;
        while (p1 < m && p2 < n) {
            if (nums1[p1] == nums2[p2]) {
                res.push_back(nums1[p1]);
                ++p1;
                ++p2;
            }
            else if (nums1[p1] < nums2[p2]) {
                ++p1;
            }
            else if (nums1[p1] > nums2[p2]) {
                ++p2;
            }
        }
        return res;
    }
};
// @lc code=end

class Solution {
public:
    // 哈希map 匹配   时间 O(m + n)  空间 O(min(m,n))
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        unordered_map<int, int> num_map;
        vector<int> res;
        // 降低空间复杂度，较短的nums添加到哈希表
        vector<int> &nums_s = m < n ? nums1 : nums2;
        vector<int> &nums_l = m < n ? nums2 : nums1;
        for (auto num : nums_s) {
            num_map[num]++;
        }
        for (int i = 0; i < nums_l.size(); ++i) {
            if (num_map.count(nums_l[i])) {
                if (num_map[nums_l[i]]-- > 0) {
                    res.push_back(nums_l[i]);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    // 排序后 匹配
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int p1 = 0, p2 = 0;
        while (p1 < m && p2 < n) {
            if (nums1[p1] == nums2[p2]) {
                res.push_back(nums1[p1]);
                ++p1;
                ++p2;
            }
            else if (nums1[p1] < nums2[p2]) {
                ++p1;
            }
            else if (nums1[p1] > nums2[p2]) {
                ++p2;
            }
        }
        return res;
    }
};
