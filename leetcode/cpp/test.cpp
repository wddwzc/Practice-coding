#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;


void processData() {
    int N;
    cin >> N;
    int res = 1;
    int dura = 0, pre_time, max_ = INT_MIN;
    stack<int> tasks;
    unordered_map<int, int> time_cost;
    for (int i = 0; i < N; ++i) {
        int time, index, state;
        cin >> time >> index >> state;
        if (tasks.empty()) {
            tasks.push(index);
        }
        else {
            dura = time - pre_time;
            // 结束
            if (state) {
                tasks.pop();
                time_cost[index] += dura;
                if (max_ < time_cost[index]) {
                    max_ = time_cost[index];
                    res = index;
                }
                else if (max_ == time_cost[index]) {
                    res = min(index, res);
                }
            }
            // 开始
            else {
                time_cost[tasks.top()] += dura;
                tasks.push(index);
            }
        }
        pre_time = time;
    }
    cout << res << endl;
    return;
}


int main()
{
    int T;
    cin >> T;
    for (int p = 0; p < T; ++p)  processData();
    system("pause");
    return 0;
}





// #include <stdio.h>
// #include <iostream>
// using namespace std;

// #pragma pack(4)
// struct data {
//     char a;
//     struct {
//         char a[5];
//         short b;
//     } s;
//     union {
//         char a[9];
//         int b;
//         // char c;
//     }u;
//     short b;
//     double c;
//     char d;
// } Data;

// int main()
// {
//     struct data d;
//     cout << sizeof(d) << endl;
//     cout << sizeof(d.s) << endl;
//     cout << sizeof(d.u) << endl;
//     system("pause");
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
 
// int huiwen(int n)    //判断回文数（详解在我BLOG里有）
// {
//     int x = 0;
//     int s = n;
//     while(s > 0) {
//         x = x * 10 + s % 10;
//         s = s / 10;
//     }
//     if(x==n) {
//         return 1;
//     }
//     else {
//         return 0;
//     }
// }
 
// int sushu(int n)    //判断素数
// {
//     int x = n;
//     int i;
//     if (n == 0 || n == 1) {
//         return 0;
//     }
//     for(i = 2; i <= n - 1; i++) {
//         if(x % i == 0)
//             return 0;
//     }
//     return 1;
// }

// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     int ans = 0;

//     for (int i = n; i <= m; i++) {
//         string cur_str = to_string(i);
//         string pre = "", last = cur_str;
//         int len = cur_str.size();
//         for (int i = 0; i < len; ++i) {
//             string now_str = cur_str.substr(i + 1, len - i - 1);
//             string now_num = pre + now_str;
//             cout << now_num << endl;
//             int num = stoi(now_num);
//             pre.push_back(cur_str[i]);
//             if(huiwen(i) && sushu(i)) {
//                 //cout << i << " ";
//                 ans++;
//             }
//         }
//     }
//     cout << ans << endl;
//     system("pause");
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
 
// int huiwen(int n)    //判断回文数（详解在我BLOG里有）
// {
//     int x = 0;
//     int s = n;
//     while(s > 0) {
//         x = x * 10 + s % 10;
//         s = s / 10;
//     }
//     if(x==n) {
//         return 1;
//     }
//     else {
//         return 0;
//     }
// }
 
// int sushu(int n)    //判断素数
// {
//     int x = n;
//     int i;
//     for(i = 2; i <= n - 1; i++) {
//         if(x % i == 0)
//             return 0;
//     }
//     return 1;
// }

// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     int ans = 0;

//     string max_str = to_string(m);
//     string min_str = to_string(n);
//     min_str = string(max_str.size() - min_str.size(), '0') + min_str;
//     for (int i = n; i <= m; i++) {
//         string cur_str = max_str;
//         for (int i = 0; i < cur_str.size(); ++i){
//             string temp_str;
//             for (int i = 0; i < )
//         }


//         if(huiwen(i) && sushu(i)) {
//             cout << i << " ";
//         }
//     }
//     system("pause");
//     return 0;
// }


// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         if (num1 == "0" || num2 == "0")  return "0";
//         int m = num1.length(), n = num2.length();
//         vector<int> median(m + n, 0);
//         int sum, n1, n2;
//         for (int i = m - 1; i >= 0; --i) {
//             n1 = num1[i] - '0';
//             for (int j = n - 1; i >= 0; --j) {
//                 n2 = num2[j] - '0';
//                 sum = n1 * n2 + median[i + j + 1];
//                 median[i + j + 1] = sum % 10;
//                 median[i + j] = sum / 10;
//             }
//         }
//         string res;
//         for (int i = 0; i < m + n; ++i) {
//             if (i == 0 && median[i] == 0) continue;
//             res.push_back(median[i] + '0');
//         }
//         return res;
//     }
// };

// int main()
// {
//     Solution sol;
//     cout << sol.multiply("123", "456") << endl;
//     system("pause");
//     return 0;
// }

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