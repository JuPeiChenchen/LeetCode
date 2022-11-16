/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(), minSuff = nums[n - 1];
        for (int i = n - 3; i >= 0; i--) {
            if (nums[i] > minSuff) {
                return false;
            }
            minSuff = min(minSuff, nums[i + 1]);
        }
        return true;
    }
};
/*class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};
*/
// @lc code=end

