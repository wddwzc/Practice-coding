#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, count = 1, max = 1;
	cin >> n;
    vector<int> stone(n);
    vector<bool> flag(n);
	for (int i = 0; i < n; i++)
	{
		cin >> stone[i];
	} 

	for (int i = 0; i < n; i++)
	{
        if (flag[i]) {
            continue;
        }
        count = 1;
        int temp = stone[i];
		for (int j = i + 1; j < n; j++)
		{
			if (temp + 1 == stone[j])//判断相邻两数字是否递增1
			{
				count = count + 1;//递增1子序列的长度
                flag[j] = true;
                temp = stone[j];
			}
		}
		if (count > max)//更新递增1子序列的长度
		{
			max = count;
		}
	}
	cout << n - max << endl;
	system("PAUSE");
}

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