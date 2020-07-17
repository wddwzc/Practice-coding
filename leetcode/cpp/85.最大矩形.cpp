/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
// 动态规划  每个点的做大高度  优化代码结构
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)  return 0;
        int m = matrix.size(), n = matrix[0].size();
        int max_S = 0;
        vector<int> left(n, 0), right(n, n), height(n, 0);
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            // 遍历每一行的时候，height记录了以当前为底的最大高度
            // 同时计算左边界
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                    left[j] = max(left[j], cur_left);
                } else {
                    height[j] = 0;
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            // 计算每个的右边界
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            // 计算最大面积
            for (int j = 0; j < n; ++j) {
                max_S = max(max_S, height[j] * (right[j] - left[j]));
            }
        }
        return max_S;
    }
};
// @lc code=end



// 类比柱状图最大矩形问题  暴力计算最大面积 O(N^2M)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)  return 0;
        int m = matrix.size(), n = matrix[0].size();
        int max_S = 0;
        // 生成每个位置结尾的最大长度
        vector<vector<int>> mask(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0')  continue;
                mask[i][j] = j > 0 ? mask[i][j - 1] + 1 : 1;

                // 以当前为右下角，计算最大矩形面积
                int width = mask[i][j];
                for (int k = i; k >= 0; --k) {
                    width = min(width, mask[k][j]);
                    max_S = max(max_S, (i - k + 1) * width);
                }
            }
        }
        return max_S;
    }
};



// 类比柱状图最大矩形问题  用栈解决最大面积问题  O(NM)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)  return 0;
        int m = matrix.size(), n = matrix[0].size();
        // 生成每个位置结尾的最大长度
        vector<vector<int>> mask(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0')  continue;
                mask[i][j] = j > 0 ? mask[i][j - 1] + 1 : 1;
            }
        }
        // 变成了柱状图最大矩形问题
        int max_S = 0;
        deque<int> h_stack;
        for (int j = 0; j < n; ++j) {
            h_stack.clear();
            vector<int> l_border(m), r_border(m, m);
            for (int i = 0; i < m; ++i) {
                while (!h_stack.empty() && mask[i][j] <= mask[h_stack.back()][j]) {
                    r_border[h_stack.back()] = i;
                    h_stack.pop_back();
                }
                l_border[i] = h_stack.empty() ? -1 : h_stack.back();
                h_stack.push_back(i);
            }
            for (int i = 0; i < m; ++i) {
                max_S = max(max_S, mask[i][j] * (r_border[i] - l_border[i] - 1));
            }
        }
        return max_S;
    }
};


// 动态规划  每个点的做大高度
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)  return 0;
        int m = matrix.size(), n = matrix[0].size();
        int max_S = 0;
        vector<int> left(n, 0), right(n, n), height(n, 0);
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            // 遍历每一行的时候，height记录了以当前为底的最大高度
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                } else {
                    height[j] = 0;
                }
                cout << height[j] << " ";
            }
            // 计算每个的左边界
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                } else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            // 计算每个的右边界
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            // 计算最大面积
            for (int j = 0; j < n; ++j) {
                max_S = max(max_S, height[j] * (right[j] - left[j]));
            }
        }
        return max_S;
    }
};


// 动态规划  每个点的做大高度  优化代码结构（把高度和左边界放一起了）
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)  return 0;
        int m = matrix.size(), n = matrix[0].size();
        int max_S = 0;
        vector<int> left(n, 0), right(n, n), height(n, 0);
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            // 遍历每一行的时候，height记录了以当前为底的最大高度
            // 同时计算左边界
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    height[j] += 1;
                    left[j] = max(left[j], cur_left);
                } else {
                    height[j] = 0;
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            // 计算每个的右边界
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            // 计算最大面积
            for (int j = 0; j < n; ++j) {
                max_S = max(max_S, height[j] * (right[j] - left[j]));
            }
        }
        return max_S;
    }
};