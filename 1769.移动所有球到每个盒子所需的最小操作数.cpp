/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result(boxes.size(), 0);
        for(int i = 0; i < boxes.size(); i++) {
            int a = 0;
            for(int j = 0; j < boxes.size(); j++) {
                if(boxes[j] == '1') {
                    a += abs(i - j);
                }
            }
            result[i] = a;
        } 
        return result;
    }
};
// @lc code=end

