#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, string> m;
    map<int, string>::iterator it;
    m[1] = "China";
    m.insert(map<int, string>::value_type(2, "C++"));
    m.erase(1);
    m.insert(make_pair<int, string>(3, "##"));
    for (it = m.begin(); it != m.end(); it++) {
        int key = it->first;
        string value = it->second;
        cout << key << ":" << value << endl;
    }
    system("pause");
    return 0;
}



// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     vector<bool> d(100, false);
//     for (int i = 1; i <= 100; ++i) {
//         for (int j = 1; j <= 100; ++j) {
//             if (j % i == 0) {
//                 d[j - 1] = (!d[j - 1]);
//             }
//         }
//     }

//     for (int i = 1; i <= 100; ++i) {
//         if (d[i - 1])  cout << i << " ";
//     }
//     cout << endl;
//     system("pause");
//     return 0;
// }