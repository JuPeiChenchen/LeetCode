/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

// @lc code=start
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int j = 1;

        for(int i = 0; i < target.size(); ) {
            if(target[i] != j) {
                string s = "Push";
                result.push_back(s);
                s = "Pop";
                result.push_back("Pop");
                j++;
            }
            else {
                string s = "Push";
                result.push_back(s);
                j++;
                i++;
            }
        }
        return result;
    }
};
// @lc code=end

