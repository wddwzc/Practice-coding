/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {

    }
};
// @lc code=end



// 统计数量，更新最小值即可
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> freq(26, INT_MAX);
        vector<int> temp_freq(26);
        for (auto &str : A) {
            temp_freq.assign(26, 0);
            for (auto &ch : str) {
                ++temp_freq[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                freq[i] = min(freq[i], temp_freq[i]);
            }
        }

        vector<string> res;
        for (int i = 0; i < 26; ++i) {
            char cur_ch = i + 'a';
            string cur_str;
            cur_str += cur_ch;
            for (int j = 0; j < freq[i]; ++j) {
                res.push_back(cur_str);
            }
        }
        return res;
    }
};