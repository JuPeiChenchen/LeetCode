/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] =='(' || s[i] == '{' || s[i] == '[') {
                str.push(s[i]);
            }
            else {
                if(str.empty()) {
                    return false;
                }
                if((str.top() == '(' && s[i] == ')') || (str.top() == '{' && s[i] == '}') || (str.top() == '[' && s[i] == ']')) {
                    str.pop();
                }
                else {
                    return false;
                }
            }
        }
        if(!str.empty()) {
            return false;
        }
        return true;
    }
};
// @lc code=end

