/*
 * @lc app=leetcode.cn id=1812 lang=cpp
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */

// @lc code=start
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        
        if((coordinates[0] - 'a') % 2 == 0){
            if((coordinates[1] - '0') % 2 ==0) {
                return true;
            }
        }
        
        else if((coordinates[0] - 'a') % 2 == 1){
            if((coordinates[1] - '0') % 2 ==1) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

