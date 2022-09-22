/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int j = s.size() - 1;
        for(int i = 0; i < s.size() / 2; i++, j--) {
            char a = s[i];
            s[i] = s[j];
            s[j] = a;
        }
    }
};
// @lc code=end

