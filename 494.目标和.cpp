/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
/*class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (abs(S) > sum) return 0; // 此时没有方案
        if ((S + sum) % 2 == 1) return 0; // 此时没有方案
        int bagSize = (S + sum) / 2;
	if (bagSize < 0) return 0;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (abs(S) > sum) return 0; // 此时没有方案
        if ((S + sum) % 2 == 1) return 0; // 此时没有方案
        int bagSize = (S + sum) / 2;
	if (bagSize < 0) return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(bagSize + 1, 0));
        for(int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1;
        }
        for(int i = 0; i <= nums[0]; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= bagSize; j++) {
                dp[i][j] = dp[i][j] + max(dp[i-1][j], dp[i][j - nums[i]]);
                cout<<dp[i][j]<<endl;
            }
        }
        return dp[nums.size()-1][bagSize];
    }
};

// @lc code=end

