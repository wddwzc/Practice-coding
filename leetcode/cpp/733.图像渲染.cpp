/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

    }
};
// @lc code=end



// flood-fill 递归
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        row = image.size();
        col = image[0].size();
        if (image[sr][sc] != newColor)
            floodFill_helper(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    void floodFill_helper(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
        image[sr][sc] = newColor;
        if (sr - 1 >= 0 && image[sr - 1][sc] == oldColor)  floodFill_helper(image, sr - 1, sc, newColor, oldColor);
        if (sr + 1 < row && image[sr + 1][sc] == oldColor)  floodFill_helper(image, sr + 1, sc, newColor, oldColor);
        if (sc - 1 >= 0 && image[sr][sc - 1] == oldColor)  floodFill_helper(image, sr, sc - 1, newColor, oldColor);
        if (sc + 1 < col && image[sr][sc + 1] == oldColor)  floodFill_helper(image, sr, sc + 1, newColor, oldColor);
        return;
    }

    int row, col;
};