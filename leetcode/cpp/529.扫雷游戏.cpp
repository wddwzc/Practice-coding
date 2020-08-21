/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

    }
};
// @lc code=end



// 广度优先搜索
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        row = board.size();
        col = board[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(row, vector<bool>(col, false));
        vector<pair<int, int>> surrouds = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        queue<pair<int, int>> poses;

        char &onclick = board[click[0]][click[1]];
        visited[click[0]][click[1]] = false;
        if (onclick == 'M') {
            onclick = 'X';
            return board;
        }
        if (onclick != 'E') {
            return board;
        }

        poses.push({click[0], click[1]});
        while (!poses.empty()) {
            int sz = poses.size();
            for (int i = 0; i < sz; ++i) {
                pair<int, int> pose = poses.front();
                poses.pop();
                int r = pose.first;
                int c = pose.second;

                int count = 0;
                // 统计周围雷的数量
                for (int j = 0; j < 8; ++j) {
                    int r_n = r + surrouds[j].first;
                    int c_n = c + surrouds[j].second;
                    if (isValid(r_n, c_n)) {
                        if (board[r_n][c_n] == 'M' || board[r_n][c_n] == 'X') {
                            ++count;
                        }
                    }
                }

                // 雷为0，可扩展
                if (count == 0) {
                    board[r][c] = 'B';
                    for (int j = 0; j < 8; ++j) {
                        int r_n = r + surrouds[j].first;
                        int c_n = c + surrouds[j].second;
                        if (isValid(r_n, c_n) && board[r_n][c_n] == 'E' && !visited[r_n][c_n]) {
                            poses.push({r_n, c_n});
                            visited[r_n][c_n] = true;
                        }
                    }
                }
                else {
                    // 不为0，就不可扩展
                    board[r][c] = '0' + count;
                }
            }
        }
        return board;
    }
    
    bool isValid(int r, int c) {
        if (r >= 0 && r < row && c >= 0 && c < col) {
            return true;
        }
        return false;
    }

    int row, col;
};