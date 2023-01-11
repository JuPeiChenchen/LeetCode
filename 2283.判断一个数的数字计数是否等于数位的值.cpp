/*
 * @lc app=leetcode.cn id=2283 lang=cpp
 *
 * [2283] 判断一个数的数字计数是否等于数位的值
 */

// @lc code=start
class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int, int> h;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            h[num[i] - '0']++;
        }
        for (int i = 0; i < n; i++) {
            int v = num[i] - '0';
            if (h[i] != v) {
                return false;
            }
        }
        return true;
    }
};

// @lc code=end

