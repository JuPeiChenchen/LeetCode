/*
 * @lc app=leetcode.cn id=1790 lang=cpp
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        char a[3];
        char b[3];
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i]) {
                a[count] = s1[i];
                b[count] = s2[i];
                count++;
                
            }
            if(count > 2) {
                return false;
            }
        }
        if(count == 1) {
            return false;
        }
        else if(count == 2) {
            if(a[0] != b[1] || a[1] != b[0]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

