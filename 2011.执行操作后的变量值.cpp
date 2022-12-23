/*
 * @lc app=leetcode.cn id=2011 lang=cpp
 *
 * [2011] 执行操作后的变量值
 */

// @lc code=start
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for(int i = 0; i < operations.size(); i++) {
            if(operations[i].find("++") != -1) {
                result++;
            }
            else {
                result--;
            }
        }
        return result;
    }
};
// @lc code=end

