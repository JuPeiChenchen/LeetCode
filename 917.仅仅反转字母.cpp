/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i, j;
        for(i = 0, j = s.size() - 1; i <= j; ) {
            if(((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))&& ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))) {
                char a = s[i];
                s[i] = s[j];
                s[j] = a;
                i++;
                j--;
            }
            else if(((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
                j--;
            }
            else if(((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))) {
                i++;
            }
            else {
                i++;
                j--;
            }
        }
        return s;
    }
};
// @lc code=end

