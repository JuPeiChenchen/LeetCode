/*
 * @lc app=leetcode.cn id=1732 lang=cpp
 *
 * [1732] 找到最高海拔
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int a = 0;
        for(int i = 0; i < gain.size(); i++) {
            result = gain[i] + result;
            a  = max(result, a);
        }
        return a;
    }
};
// @lc code=end

