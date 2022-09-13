/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[0] > target){
                return 0;
            }
            else if(nums[nums.size() - 1] < target){
                return nums.size();
            }
            else if(nums[mid] < target && nums[mid + 1] > target){
                return mid + 1;
            }
            else if(nums[mid] > target && nums[mid - 1] < target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

