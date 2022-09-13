/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    int searchLeft(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] == target){
                right = mid - 1;
            }
            else{
                right = mid - 1;
            }
        }
        return right;
    }
    int searchRight(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] == target){
                left = mid + 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(nums[left - 1] == target){
            return left;
        }
        else{
            return -1;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = searchLeft(nums, target);
        int right = searchRight(nums, target);
        if (left == -1 || right == -1)
        {
            return {-1,-1};
        }
        return {left + 1, right - 1};
        
    }
};
// @lc code=end

