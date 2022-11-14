/*
 * @lc app=leetcode.cn id=805 lang=cpp
 *
 * [805] 数组的均值分割
 */

// @lc code=start
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), m = n / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        bool isPossible = false;
        for (int i = 1; i <= m; i++) {
            if (sum * i % n == 0) {
                isPossible = true;
                break;
            }
        }  
        if (!isPossible) {
            return false;
        }
        vector<unordered_set<int>> dp(m + 1);
        dp[0].insert(0);
        for (int num: nums) {
            for (int i = m; i >= 1; i--) {
                for (int x: dp[i - 1]) {
                    int curr = x + num;
                    if (curr * n == sum * i) {
                        return true;
                    }
                    dp[i].emplace(curr);
                } 
            }
        }
        return false;
    }
};

// @lc code=end

