/*
 * @lc app=leetcode.cn id=1250 lang=cpp
 *
 * [1250] 检查「好数组」
 */

// @lc code=start
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int divisor = nums[0];
        for (int num : nums) {
            divisor = gcd(divisor, num);
            if (divisor == 1) {
                break;
            }
        }
        return divisor == 1;
    }
};


// @lc code=end

