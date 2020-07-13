#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 分治思想
class MergeSort {
public:
    // 自底向上的归并排序
    void sort_D2T(vector<int> &a) {
        int n = a.size();
        aux.resize(n);
        for (int sz = 1; sz < n; sz = sz + sz) {
            for (int lo = 0; lo < n - sz; lo += sz + sz) {
                merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
            }
        }
    }

    // 自顶向下的归并排序
    void sort_T2D(vector<int> &a) {
        aux.resize(a.size());
        sort_T2D(a, 0, a.size() - 1);
    }
    void sort_T2D(vector<int> &a, int lo, int hi) {
        if (hi <= lo)  return;
        int mid = lo + (hi - lo) / 2;
        sort_T2D(a, lo, mid);
        sort_T2D(a, mid + 1, hi);
        merge(a, lo, mid, hi);
    }
    void merge(vector<int> &a, int lo, int mid, int hi) {
        // 将a[lo..mid]和a[mid+1..hi]归并
        int i = lo, j = mid + 1;

        for (int k = lo; k <= hi; k++) {
            // 将a[lo..hi]复制到aux[lo..hi]
            aux[k] = a[k];
        }
        // 归并回到a[lo..hi]
        for (int k = lo; k <= hi; ++k) {
            if      (i < mid)           a[k] = aux[j++];
            else if (j > hi)            a[k] = aux[i++];
            else if (aux[j] < aux[i])   a[k] = aux[j++];
            else                        a[k] = aux[i++];
        }
    }

private:
    vector<int> aux;
};


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
    MergeSort merge_sort;
    merge_sort.sort_D2T(data);
    cout << "Sorted data:" << endl;
    for (auto d : data) {
        cout << d << " ";
    }
    cout << endl;
    inf.close();
    system("pause");
    return 0;
}