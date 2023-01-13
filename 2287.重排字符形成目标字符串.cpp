/*
 * @lc app=leetcode.cn id=2287 lang=cpp
 *
 * [2287] 重排字符形成目标字符串
 */

// @lc code=start
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> a(26, 0);
        vector<int> b(26, 0);
        for(int i = 0; i < s.size(); i++) {
            a[s[i] - 'a']++;
        }
        for(int i = 0; i < target.size(); i++) {
            b[target[i] - 'a']++;
        }
        int result = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(b[i] > 0 && a[i] >= b[i]) {
                result = min(result, a[i] / b[i]);
            }
            else if(b[i] > 0 && a[i] < b[i]) {
                result = 0;
                break;
            }
        }
        return result;
    }
};
// @lc code=end

