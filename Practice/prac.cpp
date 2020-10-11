#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<bool> d(100, false);
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (j % i == 0) {
                d[j - 1] = (!d[j - 1]);
            }
        }
    }

    for (int i = 1; i <= 100; ++i) {
        if (d[i - 1])  cout << i << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}