/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index = 0;
        while(nums[index] < 0) {
            index++;
        }
        int leftindex = index - 1;
        int rightindex = index;
        vector<int> result;
        int i = 0;
        while(leftindex >= 0 && rightindex <nums.size()) {
            if(nums[rightindex] * nums[rightindex] > nums[leftindex] * nums[leftindex]) {
                result[i] = nums[leftindex] * nums[leftindex];
                leftindex--;
                i++;
            }
            else {
                result[i] = nums[rightindex] * nums[rightindex];
                rightindex++;
                i++;
            }
        }
        while(leftindex >= 0) {
            result[i] = nums[leftindex] * nums[leftindex];
                leftindex--;
                i++;
        }
        while(rightindex < nums.size()) {
            result[i] = nums[rightindex] * nums[rightindex];
                rightindex++;
                i++;
        }
        return result;
    }
};
// @lc code=end

