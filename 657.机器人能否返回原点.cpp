/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> a(2,0);
        for(int i = 0; i < moves.size(); i++) {
            if(moves[i] == 'R') {
                a[0]++;
            }
            else if(moves[i] == 'L') {
                a[0]--;
            }
            else if(moves[i] == 'U') {
                a[1]--;
            }
            else {
                a[1]++;
            }
        }
        if(a[0] == 0 && a[1] == 0) {
            return true;
        }
        return false;
    }
};
// @lc code=end

