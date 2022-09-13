/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int slowindex1 = 0;
        for(int fastindex = 0; fastindex < s.length(); fastindex++)
        {
            if(s[fastindex] != '#') {
                s[slowindex1] = s[fastindex];
                slowindex1++;
            }
            else {
                if(slowindex1 != 0) {
                    slowindex1--;
                    s[slowindex1] = ' ';
                }
            }
        }
        int slowindex = 0;
        for(int fastindex = 0; fastindex < t.length(); fastindex++)
        {
            if(t[fastindex] != '#') {
                t[slowindex] = t[fastindex];
                slowindex++;
            }
            else {
                if(slowindex != 0) {
                    slowindex--;
                    t[slowindex] = ' ';
                }
            }
        }
        int a = max(slowindex1,slowindex);
        for(int i = 0; i < a; i++)
        {
            if(s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

