/*
 * @lc app=leetcode.cn id=1739 lang=cpp
 *
 * [1739] 放置盒子
 */

// @lc code=start
class Solution {
public:
    int minimumBoxes(int n) {
        int cur = 1, i = 1, j = 1;
        while (n > cur) {
            n -= cur;
            i++;
            cur += i;
        }
        cur = 1;
        while (n > cur) {
            n -= cur;
            j++;
            cur++;
        }
        return (i - 1) * i / 2 + j;
    }
};

// @lc code=end

