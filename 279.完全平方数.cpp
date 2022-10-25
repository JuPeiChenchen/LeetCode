/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
/*class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1000000);
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            if(int(sqrt(i)) * int(sqrt(i)) == i) {
                    dp[i] = 1;
                }
            else {
            for(int j = i - 1; j >= 1; j--) {
                
                    if(int(sqrt(j)) * int(sqrt(j)) == j) {
                        dp[i] = min(dp[i - j] + dp[j], dp[i]);
                        cout<<i<<"  "<<dp[i]<<endl;
                }
            }}
        }
        return dp[n];
    }
};*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++) { // 遍历背包
            for (int j = 1; j * j <= i; j++) { // 遍历物品
                dp[i] = min(dp[i - j * j] + 1 /*dp[j * j]*/, dp[i]);
            }
        }
        return dp[n];
    }
};
// @lc code=end

