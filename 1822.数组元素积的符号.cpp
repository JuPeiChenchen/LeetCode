/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 *
 * [1822] 数组元素积的符号
 */

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int flag = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                flag = flag * -1;
            }
            else if(nums[i] == 0) {
                return 0;
            }
        }
        return flag;
    }
};
// @lc code=end

