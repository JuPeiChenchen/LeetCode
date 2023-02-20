/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size() - 1; i >= 0; i--) {
            for(int j = nums.size() - 1; j > i; j--) {
                if(nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                    reverse(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end

