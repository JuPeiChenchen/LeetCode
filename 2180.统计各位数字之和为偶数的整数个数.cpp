/*
 * @lc app=leetcode.cn id=2180 lang=cpp
 *
 * [2180] 统计各位数字之和为偶数的整数个数
 */

// @lc code=start
class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for (int i = 1; i <= num; i++) {
            int x = i, sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            if (sum % 2 == 0) {
                res++;
            }
        }
        return res;
    }
};

// @lc code=end

