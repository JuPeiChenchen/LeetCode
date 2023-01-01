/*
 * @lc app=leetcode.cn id=2351 lang=cpp
 *
 * [2351] 第一个出现两次的字母
 */

// @lc code=start
class Solution {
public:
    char repeatedCharacter(string s) {
        string result;
        for(int i = 0; i < s.size(); i++) {
            if(result.find(s[i]) != -1) {
                return s[i];
            }
            else {
                result.push_back(s[i]);
            }
        }
        return s[s.size() - 1];
    }
};
/*class Solution:
    def repeatedCharacter(self, s: str) -> str:

        res = ''
        mask = 0

        for ch in s:
            if mask & (1 << (ord(ch) - ord('a'))):
                res = ch
                break

            mask |= 1 << (ord(ch) - ord('a'))
        
        return res

*/
// @lc code=end

