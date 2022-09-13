/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowindex = 0;
        int fastindex = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[fastindex] != val){
                nums[slowindex] = nums[fastindex];
                slowindex++;
            }
            fastindex++;
        }
        return slowindex;
    }
};
// @lc code=end

