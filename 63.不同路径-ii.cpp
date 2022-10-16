/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < obstacleGrid.size(); i++) {
            if(obstacleGrid[i][0] != 1) {
                dp[i][0] = 1;
            }
            else {
                dp[i][0] = 0;
                break;
            }
            
        }
        for(int j = 0; j < obstacleGrid[0].size(); j++) {
            if(obstacleGrid[0][j] != 1) {
                dp[0][j] = 1;
            }
            else {
                dp[0][j] = 0;
                break;
            }
        }
        for(int i = 1; i < obstacleGrid.size(); i++) {
            for(int j = 1; j < obstacleGrid[0].size(); j++) {
                if(obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

