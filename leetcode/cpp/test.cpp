#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")  return "0";
        int m = num1.length(), n = num2.length();
        vector<int> median(m + n, 0);
        int sum, n1, n2;
        for (int i = m - 1; i >= 0; --i) {
            n1 = num1[i] - '0';
            for (int j = n - 1; i >= 0; --j) {
                n2 = num2[j] - '0';
                sum = n1 * n2 + median[i + j + 1];
                median[i + j + 1] = sum % 10;
                median[i + j] = sum / 10;
            }
        }
        string res;
        for (int i = 0; i < m + n; ++i) {
            if (i == 0 && median[i] == 0) continue;
            res.push_back(median[i] + '0');
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.multiply("123", "456") << endl;
    system("pause");
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