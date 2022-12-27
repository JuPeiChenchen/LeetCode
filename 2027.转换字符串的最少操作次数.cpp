/*
 * @lc app=leetcode.cn id=2027 lang=cpp
 *
 * [2027] 转换字符串的最少操作次数
 */

// @lc code=start
class Solution {
public:
    int minimumMoves(string s) {
        int result = 0;
        if(s.find('X') == -1) {
            return 0;
        }
        if(s.size() == 3) {
            return 1;
        }
        int i;
        for(i = 0; i < s.size(); ) {
            if(s[i] == 'X') {
                result++;
                i += 3;
            }
            else{
                i++;
            }
        }
        /*if(s[i] == 'X' || s[i + 1] == 'X') {
            result++;
        }*/
        return result;
    }
};
// @lc code=end

