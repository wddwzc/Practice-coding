/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    // 二分法 可以用于确定一个有范围的整数
    // 用时间换空间 时间O(NlogN) 空间O(1)
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            // 统计<=mid的数量
            for (auto num : nums) {
                if (num <= mid) {
                    ++count;
                }
            }
            // 如果count大于mid，说明左区间包含重复数
            if (count > mid) {
                right = mid;
            }
            // 否则是右区间包含
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

class Solution {
public:
    // 二分法 可以用于确定一个有范围的整数
    // 用时间换空间 时间O(NlogN) 空间O(1)
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            // 统计<=mid的数量
            for (auto num : nums) {
                if (num <= mid) {
                    ++count;
                }
            }
            // 如果count大于mid，说明左区间包含重复数
            if (count > mid) {
                right = mid;
            }
            // 否则是右区间包含
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};

class Solution {
public:
    // 哈希表 做重复查找  违反限制2
    // 时间O(N) 空间O(N)
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for (auto num : nums) {
            if (num_set.find(num) != num_set.end()) {
                return num;
            }
            num_set.insert(num);
        }
        return 0;
    }
};

class Solution {
public:
    // 位运算
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        // 确定二进制下最高位是多少
        int bit_max = 31;
        while (!((n - 1) >> bit_max)) {
            bit_max -= 1;
        }
        for (int bit = 0; bit <= bit_max; ++bit) {
            int x = 0, y = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] & (1 << bit)) {
                    x += 1;
                }
                if (i >= 1 && (i & (1 << bit))) {
                    y += 1;
                }
            }
            // 如果x>y，说明该位
            if (x > y) {
                ans |= 1 << bit;
            }
        }
        return ans;
    }
};

class Solution {
public:
    // 快慢指针
    // 时间O(N) 空间O(1)
    // 参考答案
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};