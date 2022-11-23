/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 *
 * [1742] 盒子中小球的最大数量
 */

// @lc code=start
class Solution {
public:
    int func(int a) {
        int result = 0;
        while(a > 0) {
            result += a % 10;
            a = a / 10;
        }
        return result;
    }
    int countBalls(int lowLimit, int highLimit) {
        vector<int> result(highLimit + 1, 0);
        int a = INT_MIN;
        for(int i = lowLimit; i <= highLimit; i++) {
            int b = func(i);
            result[b]++;
            a = max(result[b], a);
        }
        return a;
    }
};
// @lc code=end

