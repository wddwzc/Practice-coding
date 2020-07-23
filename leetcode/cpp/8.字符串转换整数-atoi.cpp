/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        
    }
};
// @lc code=end

// 正则表达式
class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        int flag = 1;
        string pattern = "^\\s*[+-]?\\d+";
        regex r(pattern);
        smatch results;
        long sum = 0;
        if (regex_search(str, results, r)) {
            string number = results.str();
            cout << number;
            for (auto c : number) {
                if (c == '-') {
                    flag = -1;
                    continue;
                }
                else if (c == '+') {
                    continue;
                }
                else if (c == ' ') {
                    continue;
                }
                sum = sum * 10;
                sum = sum + (c - '0');
                if (flag == 1 && sum > INT_MAX) return INT_MAX;
                else if (flag == -1 && sum > long(INT_MAX) + 1) return INT_MIN;
            }
        }
        sum *= flag;
        return int(sum);
    }
};

// 逐位搜索 转换
class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        int begin = 0, flag = 1;
        while (begin < n && str[begin] == ' ') {
            ++begin;
        }
        if (begin == n)  return 0;
        if (str[begin] == '-') {
            flag = -1;
            ++begin;
        }
        else if (str[begin] == '+') {
            ++begin;
        }
        long sum = 0;
        for (int i = begin; i < n; ++i) {
            if (!isdigit(str[i]))  break;
            sum = sum * 10;
            sum += (str[i] - '0');
            if (flag == 1 && sum > INT_MAX) {
                return INT_MAX;
            }
            else if (flag == -1 && sum > long(INT_MAX) + 1) {
                return INT_MIN;
            }
        }
        sum *= flag;
        return int(sum);
    }
};