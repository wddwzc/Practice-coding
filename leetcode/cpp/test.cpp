#include <iostream>

using namespace std;

int main()
{
    long long T, l, r;
    cin >> T;
    int *hist = new int[1000000000];
    long long min_ = 0, temp;
    while (T > 0) {
        cin >> l >> r;
        int count = 0, temp;
        min_ = min(min_, l);
        for (long long i = min_; i <= r; ++i) {
            if (temp < 10) {
                if ()
            }
        }
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <unordered_map>

// using namespace std;

// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         unordered_map<int, int> mark_map;
//         stack<int> node_stack;
//         int ind, ind_linked;
//         cout << "input" << endl;
//         for (int j = 0; j < n; ++j) {
//             for (auto mark : mark_map) {
//                 cout << mark.first << " " << mark.second << endl;
//             }
//             cout << endl;

//             cout << j << endl;

            
//             if (mark_map.count(j) == 0) {
//                 mark_map[j] = 0;
//                 node_stack.push(j);
//             }
//             else {
//                 continue;
//             }

//             while (!node_stack.empty()) {
//                 ind = node_stack.top();
//                 node_stack.pop();
//                 for (int i = 0; i < graph[ind].size(); ++i) {
//                     ind_linked = graph[ind][i];
//                     if (mark_map.count(ind_linked) == 0) {
//                         mark_map[ind_linked] = mark_map[ind] ^ 1;
//                         node_stack.push(ind_linked);
//                     }
//                     else {
//                         if (mark_map[ind_linked] == mark_map[ind]) {
//                             return false;
//                         }
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };

// int main()
// {	
// 	Solution sol;
// 	vector<vector<int>> input = {{}, {3}, {}, {1}};
// 	sol.isBipartite(input);
// 	system("pause");
// 	return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
// 	int n, count = 1, max = 1;
// 	cin >> n;
//     vector<int> stone(n);
//     vector<bool> flag(n);
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> stone[i];
// 	} 

// 	for (int i = 0; i < n; i++)
// 	{
//         if (flag[i]) {
//             continue;
//         }
//         count = 1;
//         int temp = stone[i];
// 		for (int j = i + 1; j < n; j++)
// 		{
// 			if (temp + 1 == stone[j])//判断相邻两数字是否递增1
// 			{
// 				count = count + 1;//递增1子序列的长度
//                 flag[j] = true;
//                 temp = stone[j];
// 			}
// 		}
// 		if (count > max)//更新递增1子序列的长度
// 		{
// 			max = count;
// 		}
// 	}
// 	cout << n - max << endl;
// 	system("PAUSE");
// }

// int main()
// {
// 	int n, count = 1, max = 1;
// 	cin >> n;
//     vector<int> stone(n);
//     vector<int> temp(n);
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> stone[i];
// 	} 

// 	for (int i = 0; i < n; i++)
// 	{
//         count = 1;
// 		temp[i] = stone[i];//从原数组中复制第i个数字,以防止原数组在计算过程中被改变
// 		for (int j = i + 1; j < n; j++)
// 		{
// 			temp[j] = stone[j];//从原数组中复制第j个数字
// 			if (temp[i] + 1 == temp[j])//判断相邻两数字是否递增1
// 			{
// 				count = count + 1;//递增1子序列的长度
// 				temp[i] = temp[j];
// 			}
// 		}
// 		if (count > max)//更新递增1子序列的长度
// 		{
// 			max = count;
// 		}
// 	}
// 	cout << n - max << endl;
// 	system("PAUSE");
// }

// int main()
// {
//     int n, count = 1, max_ = 1;
//     cin >> n;
//     vector<int> stone(n);
//     vector<bool> flag(n, false);
//     for (int i = 0; i < n; ++i) {
//         cin >> stone[i];
//     }
//     for (int i = 0; i <= n; ++i) {
//         if (stone[i] + 1 == stone[i + 1]) {
//             ++count;
//             max_ = max(count, max_);
//         }
//         else {
//             count = 1;
//         }
//     }
//     cout << n - max_ << endl;
//     system("pause");
//     return n - max_;
// }