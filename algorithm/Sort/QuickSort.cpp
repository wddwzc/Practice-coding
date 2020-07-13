#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 快速排序（分治思想）
class QuickSort {
public:
    void sort_recursion(vector<int> &a) {
        sort_recursion(a, 0, a.size() - 1);
    }
    void sort_recursion(vector<int> &a, int lo, int hi) {
        if (hi <= lo)  return;
        // 在数组规模较小时，换成插入排序，M在5-15都是比较好的
        // if (hi <= lo + M) { Insertion.sort(a, lo, hi); return; }
        //切分
        int i = partition(a, lo, hi);
        // 对左半部分排序
        sort_recursion(a, lo, i - 1);
        // 对右半部分排序
        sort_recursion(a, i + 1, hi);
    }

    void sort_quick3way(vector<int> & a) {
        sort_quick3way(a, 0, a.size() - 1);
    }
    void sort_quick3way(vector<int> &a, int lo, int hi) {
        if (hi <= lo)  return;
        int lt = lo, i = lo + 1, gt = hi;
        int split_n = a[lo];
        while (i <= gt) {
            if (a[i] < split_n)         swap(a[lt++], a[i++]);
            else if (a[i] > split_n)    swap(a[i], a[gt--]);
            else                        i++;
        }
        // 现在 a[lo..lt-1] < v = a[lt..gt] < a[gt+1..hi]成立
        sort_quick3way(a, lo, lt - 1);
        sort_quick3way(a, gt + 1, hi);
    }


    // 原地切分
    int partition(vector<int> &a, int lo, int hi) {
        int i = lo, j = hi + 1;
        int split_n = a[i];
        while (true) {
            // 左边移动到>=split_n的位置
            while (a[++i] < split_n)  if (i == hi) break;
            // 右边移动到<=split_n的位置
            while (split_n < a[--j])  if (j == lo) break;
            // 索引重合，结束
            if (i >= j) break;
            swap(a[i], a[j]);
        }
        // 把split_n交换到分隔位置
        swap(a[lo], a[j]);
        return j;
    }
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
    QuickSort quick_sort;
    quick_sort.sort_quick3way(data);
    cout << "Sorted data:" << endl;
    for (auto d : data) {
        cout << d << " ";
    }
    cout << endl;
    inf.close();
    system("pause");
    return 0;
}