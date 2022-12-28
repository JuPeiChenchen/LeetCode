/*
 * @lc app=leetcode.cn id=1750 lang=cpp
 *
 * [1750] 删除字符串两端相同字符后的最短长度
 */

// @lc code=start
class Solution {
public:
    int minimumLength(string s) {
        int result = s.size();
        int left = 0;
        int right = s.size() - 1;
        for(; left < right; ) {
            int a = left;
            int b = right;
            while(a + 1 < b && s[a + 1] == s[a]) {
                a++;
            }
            while(b - 1 > a && s[b - 1] == s[b]) {
                b--;
            }
            if(s[a] != s[b]) {
                break;
            }
            else {
                left = a;
                right = b;
                left++;
                right--;
            }
        }
        return right - left + 1;
    }
};
// @lc code=end

