/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {

    }
};
// @lc code=end





// 数字相同，排列不同
// 找到第一个降序位置，和第一个大于它的数交换
// 由于这一部分是有序的，所以直接反转这部分即可
class Solution {
public:
    
    int nextGreaterElement(int n) {
        string num_str;
        int temp = n;
        while (temp != 0) {
            num_str.push_back(temp % 10 + '0');
            temp /= 10;
        }
        int i = 1, len = num_str.size();
        while (i < len && num_str[i] >= num_str[i - 1]) {
            ++i;
        }
        if (i >= len)  return -1;
        int j = 0;
        while (j < i && num_str[j] <= num_str[i]) {
            ++j;
        }
        swap(num_str[i], num_str[j]);
        reverse(num_str.begin(), num_str.begin() + i);
        long long res = 0;
        for (int k = len - 1; k >= 0; --k) {
            res = res * 10 + (num_str[k] - '0');
        }
        if (res > INT_MAX)  return -1;
        return (int)res;
    }
};