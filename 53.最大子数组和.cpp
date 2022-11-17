/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MIN);
        int result = INT_MIN;
        dp[0] = nums[0];
        result = max(dp[0], result);
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        for(int i = 0; i < nums.size(); i++) {
            cout<<dp[i]<<endl;
        }
        return result;
    }
};
// @lc code=end
-2
1
-2
4
3
5
6
1
5
