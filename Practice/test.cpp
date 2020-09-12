#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> p(new int(2));
    cout << sizeof(p) << endl;
    system("pause");
    return 0;
}


// #include <iostream>
// // #include "test.h"

// using namespace std;

// extern int a;

// int main()
// {
//     cout << a++ << endl;
//     system("pause");
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;


// int main()
// {
//     string input;
//     getline(cin, input);
//     int n, a, b;
//     cin >> n;
//     vector<int> mapping(10);
//     for (int i = 0; i < 10; ++i) {
//         mapping[i] = i;
//     }
//     for (int p = 0; p < n; ++p) {
//         cin >> a >> b;
//         for (int i = 0; i < 10; ++i) {
//             if (mapping[i] == a) {
//                 mapping[i] = b;
//             }
//         }
//     }
    
//     for (auto &ch : input) {
//         int val = ch - '0';
//         if (mapping[val] != val) {
//             ch = mapping[val] + '0';
//         }
//     }
//     cout << input << endl;
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
//     vector<bool> visited(n, false);
//     vector<int> res(n, -1);
//     for (int i = 0; i < n; ++i) {
//         int input;
//         for (int j = 0; j < n; ++j) {
//             cin >> input;
//             if (res[i] == -1) {
//                 if (!visited[input]) {
//                     res[i] = input;
//                     visited[input] = true;
//                 }
//             }
//         }
//     }
//     for (auto &r : res) {
//         cout << r << " ";
//     }
//     cout << endl;
//     // system("pause");
//     return 0;
// }


// #include <iostream>

// using namespace std;

// int fun6(int a) {
//     return 1;
// }

// int (*pf)(int) = fun6;

// int main()
// {
//     cout << (&pf) (256);
//     system("pause");
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;


// int main()
// {
//     string input;
//     getline(cin, input);
//     int n, a, b;
//     cin >> n;
//     vector<int> mapping(10);
//     for (int i = 0; i < 10; ++i) {
//         mapping[i] = i;
//     }
//     for (int p = 0; p < n; ++p) {
//         cin >> a >> b;
//         for (int i = 0; i < 10; ++i) {
//             if (mapping[i] == a) {
//                 mapping[i] = b;
//             }
//         }
//     }
    
//     for (auto &ch : input) {
//         int val = ch - '0';
//         if (mapping[val] != val) {
//             ch = mapping[val] + '0';
//         }
//     }
//     cout << input << endl;
//     system("pause");
//     return 0;
// }














// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// int main()
// {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<int> data(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> data[i];
//     }
//     for (int p = 0; p < m; ++p) {
//         int l, r;
//         cin >> l >> r;
//         int count = 0;

//         unordered_map<int, int> num_count;
//         for (int i = l; i <= r; ++i) {
//             num_count[data[i - 1]]++;
//         }

//         for (int i = l; i < r; ++i) {
//             int cur_num = data[i - 1];
//             num_count[cur_num]--;

//             if ((k -  cur_num) % (cur_num + 1) == 0) {
//                 int need_num = (k -  cur_num) / (cur_num + 1);
//                 if (num_count.count(need_num)) {
//                     count += num_count[need_num];
//                 }
//             }
//         }

//         cout << count << endl;
//     }
//     system("pause");
//     return 0;
// }
















// #include <iostream>
// #include <sstream>
// #include <string>
// #include <vector>
// using namespace std;


// int main()
// {
//     string input, str, match;
//     getline(cin, input);
//     cin >> match;
//     vector<int> breakpoint;
//     vector<string> str_list;
//     stringstream instr(input);
//     string full_str = "";
//     // 输入的时候 存一个去空格的string，一个按word存的序列
//     while (instr >> str) {
//         str_list.push_back(str);
//         full_str += str;
//         cout << str << endl;
//     }
//     cout << full_str << endl;
//     // // 找到每个 match 的位置
//     int pos = 0;
//     while ((pos = full_str.find(match, pos)) != full_str.npos) {
//         breakpoint.push_back(pos);
//     }

//     // 找到和match相关的word，进行处理
//     int cur_pos = 0;
//     int j = 0;
//     vector<string> res;
//     for (int i = 0; i < breakpoint.size(); ++i) {
//         while (cur_pos >= breakpoint[i]) {
//             res.push_back(str_list[j]);
//             cur_pos += str_list[j].size();
//             ++j;
//         }
        
//     }
//     system("pause");
//     return 0;
// }



























































// #include <stdio.h>
// #include <iostream>
// using namespace std;

// double fun(double a1,double a2,int b)
// {
//     switch(b) {
//         case 0: return (a1 + a2);
//         case 1: return (a1 - a2);
//         case 2: return (a1 * a2);
//         case 3: return (a1 / a2);
//     }
// }

// int main()
// {
//     int i,j,k,l,n,m,r,save[4];
//     double num[4]={1,1,1,1}, tem1, tem2, tem3, abc = 1111;
//     char sign[5]="+-*/";
//     printf("input 4 numbers:");
//     for(i = 0; i < 4; i++) {
//         scanf("%lf",num+i); save[i]=num[i];}
//     for(i = 0; i < 4; i++)
//     for(j = 0; j < 4; j++)
//     if(j != i) {
//         for(k=0;k<4;k++)
//             if(k!=i&&k!=j) {
//                 for(l=0;l<4;l++)
//                 if(l!=i&&l!=j&&l!=k) {
//                     for(n=0;n<4;n++)
//                         for(m=0;m<4;m++)
//                             for(r=0;r<4;r++) {
//                                 tem1 = fun(num[i],num[j],n);
//                                 tem2 = fun(tem1,num[k],m);
//                                 tem3 = fun(tem2,num[l],r);
//                                 if(tem3==24.0)printf("{(%d%c%d)%c%d}%c%d=24\n",save[i],sign[n],save[j],sign[m],save[k],sign[r],save[l]);
//                                 else if(tem3==-24.0)printf("{%d%c(%d%c%d)}%c%d=24\n",save[k],sign[m],save[i],sign[n],save[j],sign[r],save[l]);
//                                 else if(tem3==1.0/24.0)printf("%d%c{(%d%c%d)%c%d}=24\n",save[l],sign[r],save[i],sign[n],save[j],sign[m],save[k]);
//                                 else if(tem3==-1.0/24.0)printf("%d%c{%d%c(%d%c%d)}=24\n",save[l],sign[r],save[k],sign[n],save[i],sign[m],save[j]);
//                                 else {
//                                     tem1=fun(num[i],num[j],n);
//                                     tem2=fun(num[k],num[l],r);
//                                     tem3=fun(tem1,tem2,m);
//                                     if(tem3==24.0)
//                                         printf("(%d%c%d)%c(%d%c%d)=24\n",save[i],sign[n],save[j],sign[m],save[k],sign[r],save[l]);
//                                 }
//                             }
//                 }
//             }
//     }
//     system("pause");
//     return 0;
// }









// #include <iostream>
// #include <string>
// #include <stack>
// #include <queue>
// using namespace std;

// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

// class Solution {
// public:
//     TreeNode* catToTree(string* categories, int categoriesLen) {
//         stack<TreeNode*> path;
//         for (int i = 0; i < categoriesLen; ++i) {
//             string &cur_str = categories[i];
//             int level = cur_str.length() - 1;
//             int value = cur_str.back() - '0';
//             TreeNode* node = new TreeNode;
//             node->val = value;
//             node->left = nullptr;
//             node->right = nullptr;
//             if (level == path.size()) {
//                 if (!path.empty()) {
//                     path.top()->left = node;
//                 }
//             }
//             else {
//                 while (level != path.size()) {
//                     path.pop();
//                 }
//                 path.top()->right = node;
//             }
//             path.push(node);
//         }
//         while (path.size() > 1) {
//             path.pop();
//         }
//         return path.top();
//     }
// };

// void BFS(TreeNode* node) {
//     queue<TreeNode*> que;
//     que.push(node);
//     while (!que.empty()) {
//         int n = que.size();
//         for (int i = 0; i < n; ++i) {
//             TreeNode* cur_node = que.front();
//             que.pop();
//             cout << cur_node->val << endl;
//             if (cur_node->left)  que.push(cur_node->left);
//             else cout << "#" << endl;
//             if (cur_node->right)  que.push(cur_node->right);
//             else cout << "#" << endl;
//         }
//     }
//     return;
// }

// int main()
// {
//     string input[5] = {"1", "\t2", "\t3", "\t\t4", "\t\t\t5"};
//     Solution sol;
//     BFS(sol.catToTree(input, 5));
//     system("pause");
//     return 0;
// }







// #include <iostream>
// #include <stack>
// #include <unordered_map>
// using namespace std;


// void processData() {
//     int N;
//     cin >> N;
//     int res = 1;
//     int dura = 0, pre_time, max_ = INT_MIN;
//     stack<int> tasks;
//     unordered_map<int, int> time_cost;
//     for (int i = 0; i < N; ++i) {
//         int time, index, state;
//         cin >> time >> index >> state;
//         if (tasks.empty()) {
//             tasks.push(index);
//         }
//         else {
//             dura = time - pre_time;
//             // 结束
//             if (state) {
//                 tasks.pop();
//                 time_cost[index] += dura;
//                 if (max_ < time_cost[index]) {
//                     max_ = time_cost[index];
//                     res = index;
//                 }
//                 else if (max_ == time_cost[index]) {
//                     res = min(index, res);
//                 }
//             }
//             // 开始
//             else {
//                 time_cost[tasks.top()] += dura;
//                 tasks.push(index);
//             }
//         }
//         pre_time = time;
//     }
//     cout << res << endl;
//     return;
// }


// int main()
// {
//     int T;
//     cin >> T;
//     for (int p = 0; p < T; ++p)  processData();
//     system("pause");
//     return 0;
// }





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