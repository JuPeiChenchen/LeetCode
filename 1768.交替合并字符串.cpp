/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 *
 * [1768] 交替合并字符串
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int len1 = word1.size();
        int len2 = word2.size();
        if(len1 > len2) {
            int i = 0;
            for(; i < len2; i++) {
                s += word1[i];
                s += word2[i];
            }
            for(; i < len1; i++) {
                s += word1[i];
            }
        }
        else {
            int i = 0;
            for(; i < len1; i++) {
                s += word1[i];
                s += word2[i];
            }
            for(; i < len2; i++) {
                s += word2[i];
            }
        }
        return s;
    }
};
// @lc code=end

