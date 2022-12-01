/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int result = 1;
        int result1 = 1;
        int flag = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1] && flag == 0) {
                result++;
                flag = 1;
            }
            else if(nums[i] < nums[i - 1] && flag == 1) {
                result++;
                flag = 0;
            }
        }
        flag = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1] && flag == 1) {
                result1++;
                flag = 0;
            }
            else if(nums[i] < nums[i - 1] && flag == 0) {
                result1++;
                flag = 1;
            }
        }
        return max(result, result1);
    }
};
/*class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};*/
/*class Solution {
public:
    int dp[1005][2];
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = dp[0][1] = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i][0] = dp[i][1] = 1;

            for (int j = 0; j < i; ++j)
            {
                if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }

            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};*/
// @lc code=end

