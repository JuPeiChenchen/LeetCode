/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
/*class Solution {
public:
    int numTrees(int n) {
        int[] dp = new int[n];
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = 2 * dp[i - 1] + (dp[i - 1] - 1);
        }
        return dp[n];
    }
};*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

