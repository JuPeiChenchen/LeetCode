/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowindex = 0;
        for(int fastindex = 0; fastindex < nums.size(); fastindex++) {
            if(nums[fastindex] != 0) {
                nums[slowindex] = nums[fastindex];
                slowindex++;
            }
        }
        while(slowindex < nums.size()) {
            nums[slowindex] = 0;
            slowindex++;
        }
    }
};
// @lc code=end

