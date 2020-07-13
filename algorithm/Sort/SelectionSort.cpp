#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void SelectionSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[min], a[i]);
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
    SelectionSort(data);
    cout << "Sorted data:" << endl;
    for (auto d : data) {
        cout << d << " ";
    }
    cout << endl;
    inf.close();
    system("pause");
    return 0;
}