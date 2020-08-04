/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        
    }
};
// @lc code=end


// 优化的竖式计算
// 逐位相乘 m*n，直接加到对应的位，再进行取余、进位处理
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")  return "0";
        int m = num1.length(), n = num2.length();
        // 保存中间值
        vector<int> median(m + n, 0);
        int sum, n1, n2;
        for (int i = m - 1; i >= 0; --i) {
            n1 = num1[i] - '0';
            for (int j = n - 1; j >= 0; --j) {
                n2 = num2[j] - '0';
                // 加到对应位
                sum = n1 * n2 + median[i + j + 1];
                // 取余
                median[i + j + 1] = sum % 10;
                // 进位到高位
                median[i + j] += sum / 10;
            }
        }
        string res;
        // 转成字符串
        for (int i = 0; i < m + n; ++i) {
            // 第一位如果是0，扔掉（开头只可能由一个0）
            if (i == 0 && median[i] == 0) continue;
            res.push_back(median[i] + '0');
        }
        return res;
    }
};


// 竖式计算
// str1逐位与str2相乘，每一步结果累加
// 相加代码来自 415.字符串相机啊
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")  return "0";
        int m = num1.size(), n = num2.size();
        string ans, pre_str = "0", cur_str;
        int flag = 0, temp;
        for (int i = 0; i < m; ++i) {
            int n1 = num1[m - i - 1] - '0';
            if (n1 == 0)  continue;
            // 补0
            cur_str = string(i, '0');
            flag = 0;
            for (int j = 0; j < n; ++j) {
                int n2 = num2[n - j - 1] - '0';
                temp = n1 * n2 + flag;
                flag = temp / 10;
                temp = temp % 10;
                cur_str = (char)(temp + '0') + cur_str;
            }
            if (flag) {
                cur_str = (char)(flag + '0') + cur_str;
            }
            if (num1[m - i - 1] != '0') {
                pre_str = addStrings(pre_str, cur_str);
            }
        }
        return pre_str;
    }

    string addStrings(string &num1, string &num2) {
        int m = num1.size(), n = num2.size();
        int len = max(n, m);
        int temp, flag = 0;
        string ans;
        ans.reserve(len + 1);
        for (int i = 0; i < len; ++i) {
            temp = (i < m ? (num1[m - i - 1] - '0') : 0) + (i < n ? (num2[n - i - 1] - '0') : 0) + flag;
            flag = temp / 10;
            temp = temp % 10;
            ans.push_back(temp + '0');
        }
        if (flag) {
            ans.push_back(flag + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};