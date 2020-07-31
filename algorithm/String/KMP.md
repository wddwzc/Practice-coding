[TOC]

KMP 算法主要是通过消除主串指针的回溯来提高匹配的效率的，利用了历史匹配信息

举例说明：

str对应的next数组如下，记录的是，如果当前字符不匹配，跳转到哪个位置继续进行匹配（而不是直接跳到ind=0处开始）

| target string | A | B | A | C | D | A | B | A | B | C |
|:--------------|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|     next      |-1 | 0 | 0 | 1 | 0 | 0 | 1 | 2 | 3 | 2 |


推一遍 j、k 的变化过程可以发现，j 记录的是当前位置的**前缀**与target string匹配的次数

比如第9个字符B（ind是8），其next为3，因为ABA与target前缀重合，所以如果在B处和src匹配失败，跳回ind=3处即可

```c++
// 生成 next 数组
void Getnext(vector<int> &next, string t)
{
    int j = 0, k = -1;
    next[0] = -1;
    while(j < t.length - 1) {
        if(k == -1 || t[j] == t[k]) {
            next[++j] = ++k;
        }
        // 此语句是这段代码最反人类的地方，如果你一下子就能看懂，那么请允许我称呼你一声大神！
        else {
            k = next[k];
        }
    }
}
```

这样的next生成函数会有一个问题，比如如下这种情况：

| target string | A | B | A | B |
|:--------------|:-:|:-:|:-:|:-:|
|     next      |-1 | 0 | 0 | 1 |

ABACDA

在 src C 处不匹配，会回溯到ind=1继续，但是ind=1处的B同样不匹配，要再回溯一次，也就是next记录的不是一步到位的回溯

进行如下修改：

```c++
// 改进版本next数组生成
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
        else k = next[k];
    }
}

int KMP(string s, string t)
{
    vector<int> next(t.length());
    int i = 0, j = 0;
    Getnext(next, t);
    while(i < s.length() && j < t.length()) {
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
        return (i - t.length());
    }
    //没找到
    return -1;
}
```