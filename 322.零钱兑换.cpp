/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sum = 0;
        /*for(int i = 0; i < coins.size(); i++) {
            sum += coins[i];
        }*/
        if(amount == 0) {
            return 0;
        }
        vector<int> dp(amount + 1, 0);
        for(int i = 1; i <= amount; i++) {
            int a = 100000;
            for(int j = 0; j < coins.size(); j++) {
                if((i >= coins[j] && dp[i - coins[j]] != 0) || i - coins[j] == 0) {
                    if(a > dp[i - coins[j]]) {
                        a = dp[i - coins[j]];
                    }
                }
            }
            if(a != 100000) {
                dp[i]  = dp[i] + a + 1;
            }
            
        }
        if(dp[amount] == 0) {
            return -1;
        }
        return dp[amount];
    }
};
/*class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {  // 遍历背包
            for (int j = 0; j < coins.size(); j++) { // 遍历物品
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX ) {
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};*/
// @lc code=end

