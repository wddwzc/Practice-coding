#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string Manacher(string s) {
    if (s.length() < 2) {
        return s;
    }
    // 第一步：预处理，将原字符串转换为新字符串
    string t = "$";
    for (auto ch : s)  t += "#" + ch;
    // 尾部再加上字符@，变为奇数长度字符串
    t += "#@";
    // 第二步：计算数组p、起始索引、最长回文半径
    int n = t.length();
    // p数组
    vector<int> p(n, 0);
    int id = 0, mx = 0;
    // 最长回文子串的长度
    int maxLength = -1;
    // 最长回文子串的中心位置索引
    int index = 0;
    for (int i = 1; i < n - 1; ++i) {
        // 参看前文第五部分
        if (mx > i)  p[i] = min(p[2 * id - i], mx - i);
        else         p[i] = 1;
        // 向左右两边延伸，扩展右边界
        while (t[i + p[i]] == t[i - p[i]]) {
            p[i]++;
        }
        // 如果回文子串的右边界超过了mx，则需要更新mx和id的值
        if (mx < p[i] + i) {
            mx = p[i] + i;
            id = i;
        }
        // 如果回文子串的长度大于maxLength，则更新maxLength和index的值
        if (maxLength < p[i] - 1) {
            // 参看前文第三部分
            maxLength = p[i] - 1;
            index = i;
        }
    }
    // 第三步：截取字符串，输出结果
    // 起始索引的计算参看前文第四部分
    int start = (index - maxLength) / 2;
    return s.substr(start, maxLength);
}

int main()
{
    cout << Manacher("abcbabcdcba") << endl;
    system("pause");
    return 0;
}
