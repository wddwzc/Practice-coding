// 快速排序
#include <iostream>
#include <vector>
using namespace std;

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
		quickSort(low, begin - 1, sortdata);
		quickSort(begin + 1, high, sortdata);
	}
}

int main()
{
	vector<int> data{ 0, 12, 56, 79, 83, 54, 25, 78, 99, 17, 33, 87, 45, 43 };
	cout << endl << data.size() << endl << endl;
	quickSort(1, data.size() - 1, data);
	for (int i = 1; i < data.size(); ++i) {
		cout << data[i] << endl;
	}
	system("pause");
	return 0;
}
