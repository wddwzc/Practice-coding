/*
 * @lc app=leetcode.cn id=923 lang=cpp
 *
 * [923] 三数之和的多种可能
 */

// @lc code=start
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {

    }
};
// @lc code=end


// 暴力搜索  超时
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int n = A.size();
        long long count = 0, add = 0, pre = 0;
        long long limit = 10^9 + 7;
        sort(A.begin(), A.end());
        for (int i = 0; i < n - 2; ++i) {
            int p1 = i + 1, p2 = i + 2;
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (A[i] + A[j] + A[k] == target) {
                        count++;
                    }
                    else if (A[i] + A[j] + A[k] > target) {
                        break;
                    }
                }
            }
        }
        return count % limit;
    }
};