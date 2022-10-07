/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int>vec;
    void traversal(vector<int>& candidates, int target, int count, int start) {
        if(count == target) {
            result.push_back(vec);
            return;
        }
        /*if(count > target) {
            return;
        }*/
        for(int i = start; i < candidates.size() && count + candidates[i] <= target; i++) {
            vec.push_back(candidates[i]);
            traversal(candidates, target, count + candidates[i], i);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        traversal(candidates, target, 0, 0);
        return result;
    }
};
// @lc code=end

