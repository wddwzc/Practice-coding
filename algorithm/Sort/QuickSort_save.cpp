// 快速排序
#include <iostream>
#include <vector>
using namespace std;

// 自己写的快排
void quickSort(int low, int high, vector<int> &sortdata) {
	if (low >= high) {
		return;
	}
	else {
		int begin = low, end = high;
		sortdata[0] = sortdata[begin];
		bool direct = true; // true for end, false for begin
		while (!(begin == end)) {
			if (direct) {
				if (sortdata[end] < sortdata[0]) {
					sortdata[begin] = sortdata[end];
					direct = !direct;
				}
				else {
					--end;
				}
			}
			else {
				if (sortdata[begin] > sortdata[0]) {
					sortdata[end] = sortdata[begin];
					direct = !direct;
				}
				else {
					++begin;
				}
			}
		}
		sortdata[begin] = sortdata[0];
		// 输出每轮结果
		for (int i = 1; i < sortdata.size(); ++i) {
			cout << sortdata[i] << " ";
		}
		cout << endl;
		quickSort(low, begin - 1, sortdata);
		quickSort(begin + 1, high, sortdata);
	}
}


// 相对低效的快排，在科大讯飞的面试题里见到的
void quickSort_naive(vector<int> &a, int left, int right) {
	if (left >= right) {
		return;
	}
	int prior = a[left];
	int i = left, j = right;
	while (i < j) {
		while (j > i && a[j] >= prior) --j;
		while (i < j && a[i] <= prior) ++i;
		if (i < j)  swap(a[i], a[j]);
		else 		swap(a[left], a[i]);
	}
	// 输出每轮结果
	for (auto c : a)  cout << c << " ";
	cout << endl;
	quickSort_naive(a, left, i - 1);
	quickSort_naive(a, i + 1, right);
}


int main()
{
	vector<int> data = { 0, 12, 56, 79, 83, 54, 25, 78, 99, 17, 33, 87, 45, 43 };
	cout << endl << data.size() << endl << endl;
	quickSort(1, data.size() - 1, data);
	vector<int> data1 = { 25, 84, 21, 47, 15, 27, 68, 35, 20 };
	cout << endl << data1.size() << endl << endl;
	quickSort_naive(data1, 0, data1.size() - 1);
	system("pause");
	return 0;
}
