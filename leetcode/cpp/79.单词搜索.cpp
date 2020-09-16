/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
    }
};
// @lc code=end










// dfs
// 回溯 + 剪枝
class Solution {
public:
    vector<vector<int>> directs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool helper(vector<vector<char>> &board, vector<vector<bool>> &visited, string &curWord, int i, int j) {
        visited[i][j] = true;
        curWord += board[i][j];

        bool flag = false;
        if (curWord.size() == target.size()) {
            if (curWord == target) {
                flag = true;
            }
        }
        else if (curWord.back() == target[curWord.size() - 1]) {
            for (auto &direct : directs) {
                int cur_i = i + direct[0];
                int cur_j = j + direct[1];
                if (cur_i >= 0 && cur_i < row && cur_j >= 0 && cur_j < col && !visited[cur_i][cur_j]) {
                    flag = helper(board, visited, curWord, cur_i, cur_j);
                }
                if (flag)  break;
            }
        }
        curWord.pop_back();
        visited[i][j] = false;
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        row = board.size(), col = board[0].size();
        int len = word.length();
        if (len > row * col)  return false;

        target = word;
        string cur_word = "";
        bool valid = false;
        vector<vector<bool>> visited(row, vector<bool>(col));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0]) {
                    valid = helper(board, visited, cur_word, i, j);
                }
                if (valid)  return true;
            }
        }
        return false;
    }

    int row, col;
    string target;
};