#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)  return 0;
    if (n == 1)  {
        cout << 1 << endl;
        return 0;
    }
    vector<vector<long long>> matrix = vector<vector<long long>>(n, vector<long long>(n, 0));
    vector<long long> num_list = vector<long long>(n * n);
    vector<pair<int, int>> directs{{1,0}, {0,1}, {0,-1}, {-1,0}};
    num_list[0] = 1;
    num_list[1] = 1;
    for (int i = 2; i < n * n; ++i) {
        num_list[i] = num_list[i - 1] + num_list[i - 2];
    }
    int count = 0;
    int cur_x = 0, cur_y = 0, direct = 0;
    while (count < (n * n - 1)) {
        int next_x = cur_x + directs[direct].first;
        int next_y = cur_y + directs[direct].second;
        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || matrix[next_y][next_x] != 0) {
            direct = (direct + 1) % 4;
        }
        else {
            matrix[cur_y][cur_x] = num_list[n * n - count - 1];
            ++count;
            cur_x = next_x;
            cur_y = next_y;
        }
    }
    matrix[cur_y][cur_x] = num_list[0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}








// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     if (n == 0)  return 0;
//     vector<vector<long long>> matrix = vector<vector<long long>>(n, vector<long long>(n, 0));
//     vector<long long> num_list = vector<long long>(n * n);
//     num_list[0] = 1;
//     num_list[1] = 1;
//     for (int i = 2; i < n * n; ++i) {
//         num_list[i] = num_list[i - 1] + num_list[i - 2];
//     }
//     int up = 0, down = n - 1, left = 0, right = n - 1;
//     int index = n * n - 1;
//     while (left <= right && up <= down) {
// 		for (int i = left; i <= right; i++) {
// 			matrix[up][i] = num_list[index];
//             index--;
//         }
//         for (int i = up + 1; i <= down; i++) {
//             matrix[i][right] = num_list[index];
//             index--;
//         }
//         if (up < down && left < right) {
//             for (int i = right - 1; i >= left; --i) {
//                 matrix[down][i] = num_list[index--];
//             }
//         }
//         if (up + 1 < down && left < right) {
//             for (int i = down - 1; i > up; --i) {
//                 matrix[i][left] = num_list[index--];
//             }
//         }
//         ++up;
//         --down;
//         ++left;
//         --right;
//     }
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }













// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     int n, count = 0;
//     vector<pair<int, int>> res;
//     cin >> n;
//     for (int i = 1; i < 9; ++i) {
//         for (int j = 0; j < 9; ++j) {
//             for (int k = 0; k < 9; ++k) {
//                 int abc = i * 100 + j * 10 + k;
//                 int acc = i * 100 + k * 10 + k;
//                 if (abc + acc == n) {
//                     ++count;
//                     res.push_back({abc, acc});
//                 }
//             }
//         }
//     }
//     cout << count << endl;
//     for (auto r : res) {
//         cout << r.first << " " << r.second << endl;
//     }
//     system("pause");
//     return 0;
// }