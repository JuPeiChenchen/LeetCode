/*
 * @lc app=leetcode.cn id=2185 lang=cpp
 *
 * [2185] 统计包含给定前缀的字符串
 */

// @lc code=start
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int result = 0;
        for(int i = 0; i < words.size(); i++) {
            string s = words[i].substr(0, pref.size());
            if(s == pref) {
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

