/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
//wfp
    int mySqrt(int x) {
        if(x == 0 || x == 1){
            return x;
        }
        int low = 0;
        int high = x;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(mid  == x / mid){
                return mid;
            }
            else if(mid  > x / mid){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low - 1;
    }
};
// @lc code=end

