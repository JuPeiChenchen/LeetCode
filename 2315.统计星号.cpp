/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 *
 * [2315] 统计星号
 */

// @lc code=start
class Solution {
public:
    int countAsterisks(string s) {
        stack<char> st;
        int result = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*' && st.empty()) {
                result++;
            }
            else if(s[i] == '|' && st.empty()) {
                st.pop();
            }
            else if(s[i] == '|') {
                st.push(s[i]);
            }
        }
        return result;
    }
};
// @lc code=end

