#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void InsertSort(vector<int> &a) {
    int n = a.size();
    for (int i = 1; i < n; ++i) {
        int min = i;
        for (int j = i; j > 0; --j) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
            }
            else {
                break;
            }
        }
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

    InsertSort(data);

    cout << "Sorted data:" << endl;
    for (auto d : data) {
        cout << d << " ";
    }
    cout << endl;
    inf.close();
    system("pause");
    return 0;
}