/*
 * @lc app=leetcode.cn id=1784 lang=cpp
 *
 * [1784] 检查二进制字符串字段
 */

// @lc code=start
/*class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;
        for(int i = 1; i < s.size(); i++) {
            if((s[i - 1] == '1' && s[i] != '1')|| (s[i - 1] == '0' && s[i] != '0'))  count++;
            if(count > 1) return false;
        }
        return true;
    }
};*/
class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};

// @lc code=end

