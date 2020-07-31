#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Getnext(vector<int> &next, string t)
{
    int j = 0, k = -1;
    next[0] = -1;
    while(j < t.length() - 1) {
        if(k == -1 || t[j] == t[k]) {
            if(t[++j] == t[++k]) {
                // 当两个字符相同时，就跳过
                // 直接一步到位
                next[j] = next[k];
            }
            else {
                next[j] = k;
            }
        }
        else {
            k = next[k];
        }
    }
}

int KMP(string s, string t)
{
    vector<int> next(t.length());
    int i = 0, j = 0;
    Getnext(next, t);
    while(i < s.length() && j < t.length()) {
        cout << i << " " << j << endl;
        if(j == -1 || s[i] == t[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];  //j回退
        }
    }
    //匹配成功，返回子串的位置
    if(j >= t.length()) {
        cout << i << " " << t.length() << endl;
        return (i - t.length());
    }
    //没找到
    return -1;
}

int main()
{
    string src = "ABCDEFGABCABERK";
    string target = "ABCABE";
    cout << KMP(src, target) << endl;
    system("pause");
    return 0;
}