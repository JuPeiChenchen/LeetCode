/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0;
        int high = num;
        if(num == 1){
            return true;
        }
        while(low <= high){
            int mid = low + (high - low ) / 2;
            if(mid == num / mid && num % mid == 0){
                return true;
            }
            else if(mid > num / mid){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

