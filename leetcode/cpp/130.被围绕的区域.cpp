/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
    }
};
// @lc code=end



// 并查集
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        row = board.size(), col = board[0].size();
        setup(row * col + 1);
        // 把边缘上的都和edge相连
        int edge = row * col;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                        // 和edge相连
                        Union(edge, i * col + j);
                    }
                    else {
                        if (board[i][j + 1] == 'O')  Union(col * i + j, col * i + j + 1);
                        if (board[i][j - 1] == 'O')  Union(col * i + j, col * i + j - 1);
                        if (board[i + 1][j] == 'O')  Union(col * i + j, col * (i + 1) + j);
                        if (board[i - 1][j] == 'O')  Union(col * i + j, col * (i - 1) + j);
                    }
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O' && !isConnected(col * i + j, edge)) {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }

    int row, col;
    vector<int> parents;
    void setup(int totalNodes) {
        parents.resize(totalNodes);
        for (int i = 0; i < totalNodes; i++) {
            parents[i] = i;
        }
    }

	// 合并连通区域是通过find来操作的, 即看这两个节点是不是在一个连通区域内.
    void Union(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        if (root1 != root2) {
            parents[root2] = root1;
        }
    }

    int find(int node) {
        while (parents[node] != node) {
            // 当前节点的父节点 指向父节点的父节点.
            // 保证一个连通区域最终的parents只有一个.
            parents[node] = parents[parents[node]];
            node = parents[node];
        }
        return node;
    }

    bool isConnected(int node1, int node2) {
        return find(node1) == find(node2);
    }
};



// DFS
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        row = board.size(), col = board[0].size();
        vector<vector<int>> mask(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i) {
            if (!mask[i][0])  BFS(board, mask, make_pair(i, 0));
            if (!mask[i][col - 1])  BFS(board, mask, make_pair(i, col- 1));
        }
        for (int j = 0; j < col; ++j) {
            if (!mask[0][j])  BFS(board, mask, make_pair(0, j));
            if (!mask[row - 1][j])  BFS(board, mask, make_pair(row - 1, j));
        }

        // for (auto line : mask) {
        //     for (auto num : line) {
        //         cout << num;
        //     }
        //     cout << endl;
        // }

        for (int i = 1; i < row - 1; ++i) {
            for (int j = 1; j < col - 1; ++j) {
                if (mask[i][j] == 1) {
                    continue;
                }
                else if (board[i][j] == 'X') {
                    mask[i][j] = 1;
                }
                else if (board[i][j] == 'O') {
                    mask[i][j] = 1;
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }

    void BFS(vector<vector<char>>& board, vector<vector<int>> &mask, pair<int, int> pose) {
        if (board[pose.first][pose.second] != 'O') return;
        mask[pose.first][pose.second] = 1;
        stack<pair<int, int>> poses;
        pair<int, int> pos;
        poses.push(pose);
        while (!poses.empty()) {
            pos = poses.top();
            poses.pop();
            int m, n;
            for (auto direct : directs) {
                m = pos.first + direct.first;
                n = pos.second + direct.second;
                if (m >= 0 && m < row && n >= 0 && n < col) {
                    if (board[m][n] == 'O') {
                        if (!mask[m][n]) {
                            mask[m][n] = 1;
                            poses.push(make_pair(m, n));
                        }
                    }
                }
            }
        }
        return;
    }
    int row, col;
    vector<pair<int, int>> directs{{0,1},{0,-1},{1,0},{-1,0}};
};