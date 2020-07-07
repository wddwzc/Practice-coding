/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		if (s.length() < p.length()) {
			return res;
		}
		string tstr(26, 0);
		string matchstr(26, 0);
		int len = p.length();
		for (int i = 0; i < len; ++i) {
			tstr[p[i] - 'a'] += 1;
			matchstr[s[i] - 'a'] += 1;
		}
		if (tstr == matchstr) {
			res.push_back(0);
		}
		for (int i = 1; i < s.length() - len; ++i) {
			matchstr[s[i - 1] - 'a'] -= 1;
			matchstr[s[i + len - 1] - 'a'] += 1;
			if (tstr == matchstr) {
				res.push_back(i);
			}
		}
		for (auto r : res) {
			cout << r << endl;
		}
		return res;
	}
};
// @lc code=end

