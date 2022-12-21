
/*
 * @lc app=leetcode.cn id=1753 lang=cpp
 *
 * [1753] 移除石子的最大得分
 */

// @lc code=start
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        int maxVal = max({a, b, c});
        if (sum - maxVal < maxVal) {
            return sum - maxVal;
        } else {
            return sum / 2;
        }
    }
};

// @lc code=end

