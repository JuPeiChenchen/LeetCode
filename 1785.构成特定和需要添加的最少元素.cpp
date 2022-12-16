 /*
 * @lc app=leetcode.cn id=1785 lang=cpp
 *
 * [1785] 构成特定和需要添加的最少元素
 */

// @lc code=start
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        long long diff = abs(sum - goal);
        return (diff + limit - 1) / limit;
    }
};

// @lc code=end

