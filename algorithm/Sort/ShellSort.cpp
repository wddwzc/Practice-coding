#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void ShellSort(vector<int> &a) {
    int n = a.size();
    int h = 1;
    while (h < n / 3) {
        // 1 4 13 40 121 364 1093
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < n; ++i) {
            // a[i]插入到a[i-h],a[i-2h],a[i-3h]
            for (int j = i; j >= h; j -= h) {
                if (a[j] < a[j - h]) {
                    swap(a[j], a[j - h]);
                }
                else {
                    break;
                }
            }
        }
        h = h / 3;
    }
    
}

int main()
{
    vector<int> data;
    ifstream inf("./algorithm/Sort/SortData.txt");
    if (!inf) {
        cout << "Failed to open the file" << endl;
        return 0;
    }
    while (!inf.eof()) {
        int temp;
        inf >> temp;
        data.push_back(temp);
    }
    cout << "Source data:" << endl;
    for (auto d : data) {
        cout << d << " ";
    }
    cout << endl;
    ShellSort(data);
    cout << "Sorted data:" << endl;
    for (auto d : data) {
        cout << d << " ";
    }
    cout << endl;
    inf.close();
    system("pause");
    return 0;
}