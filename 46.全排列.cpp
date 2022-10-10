/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
/*class Solution {
public:
    vector<vector<int>> result;
    
    unordered_set<int> set;
    void traversal(vector<int>& nums) {
        if(set.size() == nums.size()) {
            vector<int> path(set.begin(), set.end());
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(set.find(nums[i]) != set.end()) {
                continue;
            }
            else {
                set.insert(set.end(), nums[i]);
            }
            traversal(nums);
            set.erase(nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        traversal(nums);
        return result;
    }
};*/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue; // path里已经收录的元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end

