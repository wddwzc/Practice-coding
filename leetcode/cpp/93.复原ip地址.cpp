/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        count = 0;
        num_dot = 0;
        judgeIP(s, 0, "");
        return res;
    }

    bool valid(string seg) {
        int len = seg.length();
        if (len > 3)
            return false;
        return (seg[0] != '0') ? (stoi(seg) <= 255) : (len == 1);
    }

    void judgeIP(string &s, int begin, string IP) {
        if (num_dot == 3) {
            string sub = s.substr(begin, n - begin);
            if (valid(sub)) {
                IP += sub;
                res.push_back(IP);
            }
            return;
        }
        for (int i = 1; i < n - begin; ++i) {
            string temp_ip = IP;
            string sub = s.substr(begin, i);
            if (valid(sub)) {
                ++num_dot;
                temp_ip += sub + ".";
                judgeIP(s, begin + i, temp_ip);
                --num_dot;
            }
            else {
                break;
            }
        }
        return;
    }

    int n, num_dot;
    int count;
    vector<string> res;
};
// @lc code=end


// 回溯  类似全排列，写的比较啰嗦
// 考虑积重特殊情况：不能有占位0；stoi超限判断
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        count = 0;
        num_dot = 0;
        judgeIP(s, 0, "");
        return res;
    }

    void judgeIP(string &s, int begin, string IP) {
        if (num_dot == 3) {
            if (n - begin != 1 && s[begin] == '0')  return;
            string sub = s.substr(begin, min(n - begin, 3));
            if (n - begin <= 3 && stoi(sub) <= 255) {
                IP += sub;
                res.push_back(IP);
            }
            return;
        }
        for (int i = 1; i < n - begin; ++i) {
            string temp_ip = IP;
            string sub = s.substr(begin, i);
            if (stoi(sub) <= 255) {
                if (i != 1 && s[begin] == '0')  break; 
                ++num_dot;
                temp_ip += sub + ".";
                judgeIP(s, begin + i, temp_ip);
                --num_dot;
            }
            else {
                break;
            }
        }
        return;
    }

    int n, num_dot;
    int count;
    vector<string> res;
};


// 判断有效段封装了一下，看起来稍微清晰一些
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        count = 0;
        num_dot = 0;
        judgeIP(s, 0, "");
        return res;
    }

    bool valid(string seg) {
        int len = seg.length();
        if (len > 3)
            return false;
        return (seg[0] != '0') ? (stoi(seg) <= 255) : (len == 1);
    }

    void judgeIP(string &s, int begin, string IP) {
        // 如果已经有3个dot，判断最后段是否合法
        if (num_dot == 3) {
            string sub = s.substr(begin, n - begin);
            if (valid(sub)) {
                IP += sub;
                res.push_back(IP);
            }
            return;
        }
        for (int i = 1; i < n - begin; ++i) {
            string temp_ip = IP;
            string sub = s.substr(begin, i);
            if (valid(sub)) {
                ++num_dot;
                temp_ip += sub + ".";
                judgeIP(s, begin + i, temp_ip);
                --num_dot;
            }
            else {
                break;
            }
        }
        return;
    }

    int n, num_dot;
    int count;
    vector<string> res;
};