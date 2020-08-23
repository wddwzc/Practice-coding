/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {

    }
};
// @lc code=end



// 本体关键是找 m 和 n 的公共前缀


// Brian Kernighan 算法
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            // 抹去最右边的 1
            n = n & (n - 1);
        }
        return n;
    }
};


// 位移
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        // 找到公共前缀
        while (m < n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};


// 添加了一些提前跳出条件的暴力方法，还是超时
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long long num = m, begin = m, end = m;
        // 获取最高位的1
        long long upper = 0;
        while (end != 0) {
            upper = 1 + upper * 2;
            end = end >> 1;
            // cout << upper << " " << end << endl;
        }
        ++upper;
        end = min(upper, (long long)n);
        for (long long i = begin + 1; i <= end; ++i) {
            num = num & i;
            if (num == 0)  return num;
        }   
        return num;
    }
};