/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slowindex = 0;
        int fastindex = 0;
        int result = 10000000;
        int sum = 0;
        for(; fastindex < nums.size(); fastindex++) {
            sum += nums[fastindex];
            while(sum >= target) {
                int sbusquence = fastindex - slowindex + 1;
                result = result < sbusquence ? result : sbusquence;
                sum -= nums[slowindex];
                slowindex++;
            }
        }
        return result == 10000000 ? 0 : result;
    }
};
// @lc code=end

