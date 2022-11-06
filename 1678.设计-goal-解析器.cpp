/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */

// @lc code=start
class Solution {
public:
    string interpret(string command) {
        string res;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                res += "G";
            } else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    res += "o";
                } else {
                    res += "al";
                }
            }
        }
        return res;
    }
};

// @lc code=end

