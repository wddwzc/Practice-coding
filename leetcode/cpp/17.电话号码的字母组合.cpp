/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {

    }
};
// @lc code=end



// 递归DFS 枚举所有情况
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        len = digits.length();
        unordered_map<char, vector<char>> mapping = { {'2', {'a','b','c'}},
                                                        {'3', {'d','e','f'}},
                                                        {'4', {'g','h','i'}},
                                                        {'5', {'j','k','l'}},
                                                        {'6', {'m','n','o'}},
                                                        {'7', {'p','q','r', 's'}},
                                                        {'8', {'t','u','v'}},
                                                        {'9', {'w','x','y','z'}} };

        helper(mapping, 0, digits, "");
        return res;
    }

    void helper(unordered_map<char, vector<char>> &mapping, int pos, string str, string trans) {
        if (pos >= len) {
            if (!trans.empty())  res.push_back(trans);
            return;
        }
        if (mapping.count(str[pos])) {
            vector<char> &mapping_alpha = mapping[str[pos]];
            for (auto ch : mapping_alpha) {
                helper(mapping, pos + 1, str, trans + ch);
            }
        }
        else {
            helper(mapping, pos + 1, str, trans);
        }
        return;
    }

    int len;
    vector<string> res;
};




// 用 vector 回溯 优化了存储，但不知道为啥时间变长了
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        len = digits.length();
        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string trans = "";
        helper(mapping, 0, digits, trans);
        return res;
    }

    void helper(vector<string> &mapping, int pos, string &str, string &trans) {
        if (pos >= len) {
            if (!trans.empty())  res.push_back(trans);
            return;
        }
        int ind = str[pos] - '0' - 2;
        for (auto ch : mapping[ind]) {
            trans += ch;
            helper(mapping, pos + 1, str, trans);
            trans.erase(trans.size() - 1);
        }
        return;
    }

    int len;
    vector<string> res;
};
