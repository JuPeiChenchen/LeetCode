/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    
    vector<int> path;
    void traversal(vector<int>& nums, vector<int>& used) {
        if(path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++) {
            if(used[i] == 1 || set.find(nums[i]) != set.end()) {
                continue;
            }
            used[i] = 1;
            set.insert(nums[i]);
            path.push_back(nums[i]);
            traversal(nums, used);
            used[i] = 0;
            //set.erase(nums[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        traversal(nums, used);
        return result;
    }
};
// @lc code=end

