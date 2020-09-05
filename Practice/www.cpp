#include <iostream>
#include "test.h"

using namespace std;

extern int a;






// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <set>
// using namespace std;

// vector<int> parents;

// bool flag = true;

// int find(int index) {
//     // while (parents[index] != index) {
//     //     parents[index] = parents[parents[index]];
//     // }
//     if (parents[index] != index) {
//         parents[index] = find(parents[index]);
//     }
    
//     return parents[index];
// }

// void Union(int x, int y) {
//     parents[find(x)] = find(parents[y]);
//     return;
// }

// void dfs(unordered_map<int, set<int>> &mapping, int index_judge, int index2);

// int main()
// {
//     unordered_map<string, int> indexes;
//     unordered_map<long long, string> ops;
//     int index = 0;
//     int N, M;
//     cin >> N;
//     for (int p = 0; p < N; ++p) {
//         cin >> M;
//         string str;
//         vector<string> equa_p1, equa_p2, equa_ops;
//         vector<string> nequa_p1, nequa_p2, nequa_ops;
//         vector<string> big_p1, big_p2, big_ops;
        
//         for (int q = 0; q < M; ++q) {
//             cin >> str;
//             // cout << str << endl;
//             int pos;
//             string param1, param2, op;
//             for (pos = 0; pos < str.size(); ++pos) {
//                 if (!isalnum(str[pos])) {
//                     param1 = str.substr(0, pos);
//                     if (str[pos] == '!') {
//                         op = str.substr(pos, 2);
//                         param2 = str.substr(pos + 2, str.size() - pos - 2);
//                     }
//                     else {
//                         op = str.substr(pos, 1);
//                         param2 = str.substr(pos + 1, str.size() - pos - 1);
//                     }

//                     // cout << param1 << " " << op << " " << param2 << endl;

//                     int ind1, ind2;
//                     if (!indexes.count(param1)) {
//                         ind1 = index;
//                         indexes[param1] = index++;
//                     }  
//                     if (!indexes.count(param2)) {
//                         ind2 = index;
//                         indexes[param2] = index++;
//                     }
//                     // ops[ind1 * 1000000 + ind2] = op;

//                     if (op == "!=") {
//                         nequa_p1.push_back(param1);
//                         nequa_p2.push_back(param2);
//                     }
//                     else if (op == "=") {
//                         equa_p1.push_back(param1);
//                         equa_p2.push_back(param2);
//                     }
//                     else if (op == ">") {
//                         big_p1.push_back(param1);
//                         big_p2.push_back(param2);
//                     }
//                     else if (op == "<") {
//                         big_p1.push_back(param2);
//                         big_p2.push_back(param1);
//                     }

//                     break;
//                 }
//             }
//         }

//         parents.resize(index);
//         for (int i = 0; i < index; ++i) {
//             parents[i] = i;
//         }

//         for (int i = 0; i < equa_p1.size(); ++i) {
//             int ind1 = indexes[equa_p1[i]];
//             int ind2 = indexes[equa_p2[i]];
//             Union(ind1, ind2);
//         }

//         for (int i = 0; i < nequa_p1.size(); ++i) {
//             int ind1 = find(indexes[nequa_p1[i]]);
//             int ind2 = find(indexes[nequa_p2[i]]);
//             // if (find(ind1) == find(ind2)) {
//             if (ind1 == ind2) {
//                 flag = false;
//                 break;
//             }
//         }

//         unordered_map<int, set<int>> mapping;
        
//         for (int i = 0; i < big_p1.size(); ++i) {
//             if (flag) {
//                 int ind1 = find(indexes[big_p1[i]]);
//                 int ind2 = find(indexes[big_p2[i]]);
//                 if (ind1 == ind2) {
//                     flag = false;
//                     break;
//                 }
//                 if (!mapping.count(ind1)) {
//                     mapping[ind1].insert(ind2);
//                     dfs(mapping, ind1, ind2);
//                 }
//                 else {
//                     if (!mapping[ind1].count(ind2)) {
//                         mapping[ind1].insert(ind2);
//                     }
//                     dfs(mapping, ind1, ind2);
//                 }
//             }
//             else {
//                 break;
//             }
//         }

//         if (flag)  cout << "True" << endl;
//         else        cout << "False" << endl;

//         flag = true;

//     }
    
//     system("pause");
//     return 0;
// }


// void dfs(unordered_map<int, set<int>> &mapping, int index_judge, int index2) {
//     // cout << "mapping size: " << mapping[index2].size() << endl;
//     if (!flag) return;
//     if (!mapping.count(index2)) return;
//     for (auto ele : mapping[index2]) {
//         int next = find(ele);
//         // cout << next << endl;
//         if (index_judge == next) {
//             flag = false;
//         }
//         else {
//             dfs(mapping, index_judge, next);
//         }
//     }
//     return;
// }






// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     int N, M;
//     cin >> N;
//     for (int p = 0; p < N; ++p) {
//         cin >> M;
//         string str;
//         for (int q = 0; q < M; ++q) {
//             cin >> str;
//         }
//         cout << "False" << endl;
//     }
//     return 0;
// }

































// #include <bits/stdc++.h>

// using namespace std;

// int delta;
// vector<int> level;

// void dfs(vector<vector<int>> &data, vector<bool> &visited, 
//             int number, int length, int index, long long &sum,
//          	int max_lvl = INT_MIN, int min_lvl = INT_MAX) {

//     if (number >= length - 1) {
//         ++sum;
//         return;
//     }
//     if (visited[index])  return;
//     visited[index] = true;
//     max_lvl = max(max_lvl, level[index]);
//     min_lvl = min(min_lvl, level[index]);
//     if (max_lvl - min_lvl > delta)  return;
//     if (data[index].size() == 0)  return;
//     else {
//         for (int i = 0; i < data[index].size(); ++i) {
//             if (visited[data[index][i]] == false) {
//                 dfs(data, visited, number + 1, length, data[index][i], sum, max_lvl, min_lvl);
//             }
//         }
//     }
//     return;
// }

// int main() {
//     int N;
//     cin >> N >> delta;
//     vector<vector<int>> data(N + 1, vector<int>());
//     level.resize(N + 1);
//     for (int i = 0; i < N - 1; ++i) {
//         int temp1, temp2;
//         cin >> temp1 >> temp2;
//         data[temp1].push_back(temp2);
//     }
//     for (int i = 1; i <= N; ++i)  cin >> level[i];
//     long long res = N, upper = 1000000007;
//     for (int len = 2; len <= N; ++len) {
//         for (int i = 1; i <= N + 1 - len; ++i) {
//             long long num = 0;
//             vector<bool> visited(N + 1, false);
//             dfs(data, visited, 0, len, i, num);
//             res = (res + num % upper) % upper;
//         }
//     }
//     cout << res << endl;
//     return 0;
// }



// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> nums(n + 1, 0), vec{0};
//     for (int i = 1; i<= n; ++i) {
//         cin >> nums[i];
//         nums[i] += nums[i - 1];
//     }
//     for (int i = 0; i < n; ++i) {
//         int cur;
//         cin >> cur;
//         auto iter = lower_bound(vec.begin(), vec.end(), cur);
//         vec.insert(iter, cur);
//         int max_ = 0;
//         for (int j = 0; j < vec.size() - 1; ++j) {
//             max_ = max(max_, nums[vec[j + 1] - 1] - nums[vec[j]] - (vec[j + 1] - vec[j] - 1) * nums[vec[j]]);
//         }
//         cout << max_ << endl;
//     }
//     system("pause");
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <set>
// #include <map>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> weights(n);
//     vector<int> pre(n + 1, 0);
//     vector<bool> visited(n, false);
//     vector<pair<int, int>> skips;
//     for (int i = 0; i < n; ++i) {
//         cin >> weights[i];
//         pre[i + 1] = pre[i] + weights[i];
//     }
//     skips.push_back({1, n});
//     int cur;
//     for (int i = 0; i < n; ++i) {
//         cin >> cur;
//         visited[cur - 1] = true;
//         int cur_sum = 0, max_ = 0;

//         for (int j = 0; j < skips.size(); ++j) {
//             pair<int, int> &skip = skips[j];
//             if (cur == skip.first) {
//                 skip.first = cur + 1;
//                 if (skip.first > skip.second) {
//                     skips.erase(skips.begin() + j);
//                 }
//             }
//             else if (cur > skip.first && cur < skip.second) {
                
//             }
//             else if (cur == skip.second) {
//                 skip.second = cur - 1;
//                 if (skip.second < skip.first) {
//                     skips.erase(skips.begin() + j);
//                 }
//             }
//             else {
//                 max_ = max(max_, pre[skip.second] - pre[skip.first]);
//             }
//         }


//         for (int j = 0; j < n; ++j) {
//             if (visited[j]) {
//                 max_ = max(max_, cur_sum);
//                 cur_sum = 0;
//             }
//             else {
//                 cur_sum += weights[j];
//             }
//         }
//         cout << max_ << endl;
//     }

//     system("pause");
//     return 0;
// }











// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> vs(n), ws(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> vs[i] >> ws[i];
//     }
//     vector<vector<int>> bonus(n);
//     for (int i = 0; i < n; ++i) {
//         int cur = vs[i] + ws[i] * 2;
//         bonus[i] = {cur, i};
//     }
//     vector<int> res;
//     sort(bonus.begin(), bonus.end(), [](const vector<int> &a, const vector<int> &b) { if (a[0] != b[0])  return a[0] > b[0];  return a[1] < b[1]; });
//     for (int i = 0; i < m; ++i)  res.push_back(bonus[i][1] + 1);
//     sort(res.begin(), res.end());
//     for (int i : res)  cout << i << " ";
//     return 0;
// }



// #include <iostream>
// #include <string>

// using namespace std;

// int main()
// {
//     int N;
//     cin >> N;
//     while (N) {
//         --N;
//         string input;
//         cin >> input;
//         int cnt_word = 0, cnt_num = 0;
//         bool hasResult = false;
//         for (int i = 0; i < input.size(); ++i) {
//             if (isalnum(input[i])) {
//                 if (i == 0) {
//                     if (isalpha(input[i])) {
//                         ++cnt_word;
//                     }
//                     else {
//                         cout << "Wrong" << endl;
//                         break;
//                     }
//                 }
//                 else {
//                     if (isalpha(input[i])) {
//                         ++cnt_word;
//                     }
//                     else {
//                         ++cnt_num;
//                     }
//                 }
//             }
//             else {
//                 cout << "Wrong" << endl;
//                 break;
//             }
//             if (i == input.size() - 1) {
//                 if (cnt_num == 0 || cnt_word == 0)  cout << "Wrong" << endl;
//                 else                                cout << "Accept" << endl;
//             }
            
//         }
//     }
//     return 0;
// }














// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> weights(n);
//     vector<int> pre(n + 1, 0);
//     vector<bool> visited(n, false);
//     for (int i = 0; i < n; ++i) {
//         cin >> weights[i];
//         pre[i + 1] = pre[i] + weights[i];
//     }
//     int cur;
//     for (int i = 0; i < n; ++i) {
//         cin >> cur;
//         visited[cur - 1] = true;
//         int cur_sum = 0, max_ = 0;

//         for (int j = 0; j < n; ++j) {
//             if (visited[j]) {
//                 max_ = max(max_, cur_sum);
//                 cur_sum = 0;
//             }
//             else {
//                 cur_sum += weights[j];
//             }
//         }
//         cout << max_ << endl;
//     }

//     //system("pause");
//     return 0;
// }






// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     if (n == 0)  return 0;
//     if (n == 1)  {
//         cout << 1 << endl;
//         return 0;
//     }
//     vector<vector<long long>> matrix = vector<vector<long long>>(n, vector<long long>(n, 0));
//     vector<long long> num_list = vector<long long>(n * n);
//     vector<pair<int, int>> directs{{1,0}, {0,1}, {0,-1}, {-1,0}};
//     num_list[0] = 1;
//     num_list[1] = 1;
//     for (int i = 2; i < n * n; ++i) {
//         num_list[i] = num_list[i - 1] + num_list[i - 2];
//     }
//     int count = 0;
//     int cur_x = 0, cur_y = 0, direct = 0;
//     while (count < (n * n - 1)) {
//         int next_x = cur_x + directs[direct].first;
//         int next_y = cur_y + directs[direct].second;
//         if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || matrix[next_y][next_x] != 0) {
//             direct = (direct + 1) % 4;
//         }
//         else {
//             matrix[cur_y][cur_x] = num_list[n * n - count - 1];
//             ++count;
//             cur_x = next_x;
//             cur_y = next_y;
//         }
//     }
//     matrix[cur_y][cur_x] = num_list[0];

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }

//     system("pause");
//     return 0;
// }








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