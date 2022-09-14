/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int result = 0;
        int slowindex = 0;
        int fastindex = 0;
        int ln = fruits[slowindex];
        int rn = fruits[fastindex];
        for(; fastindex < fruits.size(); fastindex++) {
            if(fruits[fastindex] == ln || fruits[fastindex] == rn) {
                int subsquence = fastindex - slowindex + 1;
                result = result > subsquence ? result : subsquence;
            }
            else {
                slowindex = fastindex - 1;
                ln = fruits[slowindex];
                while(slowindex >= 1 && fruits[slowindex - 1] == ln){ slowindex--;}
                rn = fruits[fastindex];
                int subsquence = fastindex - slowindex + 1;
                result = result > subsquence ? result : subsquence;
            }
        }
        return result;
    }
};
// @lc code=end

