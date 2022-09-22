/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
/*class Solution {
public:
    
    string reverseStr(string s, int k) {
        int n = s.length();
        int index = 1;
        for(int i = 0; i < s.length(); i += 2 * k) {
            if(i + k > s.length() - 1) {
                reverse(s.begin() + i, s.end());
            }
            else if (i + k <= s.length() - 1 && i + 2 * k > s.length() - 1) {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }
        return s;
    }
    
};*/
class Solution {
public:
    void reverse(string& s, int start, int end) {
        int j = end - 1;
        for(int i = start; i < (end + start) / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseStr(string s, int k) {
        int n = s.length();
        int index = 1;
        for(int i = 0; i < s.length(); i += 2 * k) {
            if(i + k > s.length() - 1) {
                reverse(s, i , s.length());
            }
            else {
                reverse(s, i, i + k);
            }
        }
        return s;
    }
    
};
// @lc code=end

