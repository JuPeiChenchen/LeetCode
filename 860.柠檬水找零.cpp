/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> result(3, 0);
        for(int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) {
                result[0]++;
            }
            else if(bills[i] == 10) {
                if(result[0] > 0) {
                    result[0]--;
                    result[1]++;
                }
                else {
                    return false;
                }
            }
            else {
                if(result[0] > 0 && result[1] > 0) {
                    result[0]--;
                    result[1]--;
                    result[2]++;
                }
                else if(result[0] >= 3) {
                    result[0] -= 3;
                    result[2]++;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

