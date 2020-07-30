/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        
    }
};
// @lc code=end


// 按行输出  step有规律
class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows == 1) return s;
		int step = numRows * 2 - 2; // 0 和 numRows-1 行间距
		int index = 0;// 记录s的下标
		int len = s.length();
		int add = 0; // 真实的间距
		string ret;
        // i表示行号
		for (int i = 0; i < numRows; i++) {
			index = i;
			add = i * 2;
			while (index < len)//超出字符串长度计算下一层
			{
				ret += s[index]; // 当前行的第一个字母
				add = step - add;// 第一次间距是step -2*i，第二次是2*i, 
				index += (i == 0 || i == numRows - 1) ? step : add; // 0行和最后一行使用step间距，其余使用add间距
			}
		}
		return ret;
	}
};


// 按行输出 题解
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    // cyclenLen - i 是非首位行，中间的两个间隔 
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};


// 按行排序  不需要输出空格，所以直接追加就行
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if (numRows == 1 || n <= numRows)  return s;
        vector<string> res(numRows, "");
        bool direct_flag = true;
        for (int i = 0; i < n; ++i) {
            int ind = i % (numRows - 1);
            if (ind == 0 && i != 0) {
                direct_flag = !direct_flag;
            }
            if (direct_flag) {
                res[ind] += s[i];
            }
            else {
                res[numRows - 1 - ind] += s[i];
            }
        }
        string ans;
        for (auto r : res) {
            ans += r;
        }
        return ans;
    }
};