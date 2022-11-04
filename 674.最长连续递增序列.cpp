/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = 1;
        int sum = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) {
                sum++;
            }
            else {
                if(sum > result) {
                    result = sum;
                }
                sum = 1;
            }
        }
        if(sum > result) {
            result = sum;
        }
        return result;
    }
};
/*class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int result = 1;
        vector<int> dp(nums.size() ,1);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) { // 连续记录
                dp[i + 1] = dp[i] + 1;
            }
            if (dp[i + 1] > result) result = dp[i + 1];
        }
        return result;
    }
};*/
// @lc code=end

