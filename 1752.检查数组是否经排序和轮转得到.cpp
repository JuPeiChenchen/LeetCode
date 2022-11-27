/*
 * @lc app=leetcode.cn id=1752 lang=cpp
 *
 * [1752] 检查数组是否经排序和轮转得到
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums) {
        int a = 0;
        int b = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < b) {
                b = nums[i];
                a = i;
            }
            else if(nums[i] <= b && nums[i - 1] > b) {
                b = nums[i];
                a = i;
            }
        }
        vector<int> result(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            result[i] = nums[(i + a) % nums.size()];
        }
        for(int i = 1; i < nums.size(); i++) {
            if(result[i] < result[i - 1]) {
                /*if(i == nums.size() - 1 && result[i] <= result[0]) {
                    return true;
                }*/
                return false;
            }
        }
        return true;
    }
};
/*class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), x = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                x = i;
                break;
            }
        }
        if (x == 0) {
            return true;
        }
        for (int i = x + 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return nums[0] >= nums[n - 1];
    }
};

*/
// @lc code=end

