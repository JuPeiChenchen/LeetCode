/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowindex = 0;
        for(int fastindex = 1; fastindex < nums.size(); fastindex++){
            if(nums[slowindex] != nums[fastindex])
            {
                slowindex++;
                nums[slowindex] = nums[fastindex];
                
            }
        }
        return slowindex + 1;
    }
};
// @lc code=end

