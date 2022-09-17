/*
 * @lc app=leetcode.cn id=1624 lang=cpp
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int result = -1;
        int a[26] ;
        //memset(a, -1, sizeof(a));
        fill(a, a + 26, -1) ;
        for(int i = 0; i < s.length(); i++) {
            if(a[s[i] - 'a'] >= 0) {
                result = max(i - a[s[i] - 'a'] - 1, result);
            }
            else {
                a[s[i] - 'a'] = i;
            }
        }
        return result;
    }
};
// @lc code=end

