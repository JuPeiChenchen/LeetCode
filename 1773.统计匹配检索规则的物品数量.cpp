/*
 * @lc app=leetcode.cn id=1773 lang=cpp
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int result = 0;
        int index = 0;
        if(ruleKey == "color") {
            index = 1;
        }
        else if(ruleKey == "name") {
            index = 2;
        }
        for(int i = 0; i < items.size(); i++) {
            if(items[i][index] == ruleValue) {
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

