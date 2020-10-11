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



// 三指针
// 先排序  遍历数组，用双指针完成两数之和的任务
// 需要考虑重复的情况
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int n = A.size();
        long long count = 0, limit = 1e9 + 7;
        sort(A.begin(), A.end());
        for (int i = 0; i < n - 2; ++i) {
            int j = i + 1, k = n - 1;
            int T = target - A[i];
            while (j < k) {
                // These steps proceed as in a typical two-sum.
                if (A[j] + A[k] < T)  j++;
                else if (A[j] + A[k] > T)  k--;
                else if (A[j] != A[k]) {
                    // We have A[j] + A[k] == T.
                    // Let's count "left": the number of A[j] == A[j+1] == A[j+2] == ...
                    // And similarly for "right".
                    int left = 1, right = 1;
                    while (j + 1 < k && A[j] == A[j + 1]) {
                        left++;
                        j++;
                    }
                    while (k - 1 > j && A[k] == A[k - 1]) {
                        right++;
                        k--;
                    }
                    count += left * right;
                    count %= limit;
                    j++;
                    k--;
                } else {
                    // M = k - j + 1
                    // We contributed M * (M-1) / 2 pairs.
                    count += (k - j + 1) * (k - j) / 2;
                    count %= limit;
                    break;
                }
            }
        }
        return count;
    }
};


// 数学方法
// 按顺序统计出现次数，然后遍历，分情况讨论
class Solution {
    public int threeSumMulti(int[] A, int target) {
        int MOD = 1_000_000_007;
        long[] count = new long[101];
        for (int x: A)
            count[x]++;

        long ans = 0;

        // All different
        for (int x = 0; x <= 100; ++x) {
            for (int y = x+1; y <= 100; ++y) {
                int z = target - x - y;
                if (y < z && z <= 100) {
                    ans += count[x] * count[y] * count[z];
                    ans %= MOD;
                }
            }
        }

        // x == y != z
        for (int x = 0; x <= 100; ++x) {
            int z = target - 2*x;
            if (x < z && z <= 100) {
                ans += count[x] * (count[x] - 1) / 2 * count[z];
                ans %= MOD;
            }
        }

        // x != y == z
        for (int x = 0; x <= 100; ++x) {
            if (target % 2 == x % 2) {
                int y = (target - x) / 2;
                if (x < y && y <= 100) {
                    ans += count[x] * count[y] * (count[y] - 1) / 2;
                    ans %= MOD;
                }
            }
        }

        // x == y == z
        if (target % 3 == 0) {
            int x = target / 3;
            if (0 <= x && x <= 100) {
                ans += count[x] * (count[x] - 1) * (count[x] - 2) / 6;
                ans %= MOD;
            }
        }

        return (int) ans;
    }
}



// 数学法改进
// 统计各个数量，去除为0的，得到有效序列
// 然后对这个序列做三数之和（会有重复，分类讨论）
class Solution {
    public int threeSumMulti(int[] A, int target) {
        int MOD = 1_000_000_007;

        // Initializing as long saves us the trouble of
        // managing count[x] * count[y] * count[z] overflowing later.
        long[] count = new long[101];
        int uniq = 0;
        for (int x: A) {
            count[x]++;
            if (count[x] == 1)
                uniq++;
        }

        int[] keys = new int[uniq];
        int t = 0;
        for (int i = 0; i <= 100; ++i)
            if (count[i] > 0)
                keys[t++] = i;

        long ans = 0;
        // Now, let's do a 3sum on "keys", for i <= j <= k.
        // We will use count to add the correct contribution to ans.

        for (int i = 0; i < keys.length; ++i) {
            int x = keys[i];
            int T = target - x;
            int j = i, k = keys.length - 1;
            while (j <= k) {
                int y = keys[j], z = keys[k];
                if (y + z < T) {
                    j++;
                } else if (y + z > T) {
                    k--;
                } else {  // # x+y+z == T, now calc the size of the contribution
                    if (i < j && j < k) {
                        ans += count[x] * count[y] * count[z];
                    } else if (i == j && j < k) {
                        ans += count[x] * (count[x] - 1) / 2 * count[z];
                    } else if (i < j && j == k) {
                        ans += count[x] * count[y] * (count[y] - 1) / 2;
                    } else {  // i == j == k
                        ans += count[x] * (count[x] - 1) * (count[x] - 2) / 6;
                    }

                    ans %= MOD;
                    j++;
                    k--;
                }
            }
        }

        return (int) ans;
    }
}




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