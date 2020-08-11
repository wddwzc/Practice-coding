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

int KMP(string src, string match)
{
    int lens = src.length(), lent = match.length();
    vector<int> next(match.length());
    int i = 0, j = 0;
    Getnext(next, match);
    // 这里如果用 src.length()  match.length()
    // 会出现莫名其妙的错误，不知道为啥
    while(i < lens && j < lent) {
        if(j == -1 || src[i] == match[j]) {
            i++;
            j++;
        }
        else {
            //j回退
            j = next[j];
        }
    }
    //匹配成功，返回子串的位置
    if(j >= match.length()) {
        // cout << i << " " << match.length() << endl;
        return (i - match.length());
    }
    //没找到
    return -1;
}

int main()
{
    string src = "ABCDEFGABCABERK";
    string target = "ABCABE";
    cout << "Src:    " << src << endl;
    cout << "Target: " << target << endl;
    int pos = KMP(src, target);
    string blank = "";
    if (pos) {
        blank = string(pos, ' ');
    }
    cout << endl << "KMP result:" << endl;
    cout << src << endl;
    cout << blank + target << endl;
    system("pause");
    return 0;
}