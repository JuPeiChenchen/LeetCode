/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> vec;
    void traversal(int n, int k, int start) {
        if(vec.size() == k) {
            result.push_back(vec);
            return;
        }
        for(int i = start; i <= n; i++) {
            vec.push_back(i);
            traversal(n, k, i + 1);
            vec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        traversal(n, k, 1);
        return result;
    }
};
// @lc code=end

