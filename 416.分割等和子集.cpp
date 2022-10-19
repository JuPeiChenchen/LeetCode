/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
/*class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % 2 == 1) {
            return false;
        }
        sum = sum / 2;
        //sort(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1,0));
        for(int i = nums[0]; i <= sum; i++) {
            dp[0][i] = nums[0];
        }
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j <= sum; j++) {
                if(j < nums[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                if(dp[i][j] == sum) {
                    //cout<<i<<j<<endl;
                    return true;
                }
            }
        }
        return false;
        
        

    }
};*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % 2 == 1) {
            return false;
        }
        sum = sum / 2;
        //sort(nums.begin(), nums.end());
        vector<int> dp(sum + 1, 0);
        /*for(int i = nums[0]; i <= sum; i++) {
            dp[0][i] = nums[0];
        }*/
        for(int i = 0; i < nums.size(); i++) {
            for(int j = sum; j >= 0; j--) {
                if(j < nums[i]) dp[j] = dp[j];
                else dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                if(dp[j] == sum) {
                    return true;
                }
            }
        }
        return false;
        
        

    }
};
// @lc code=end

