/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> vec;
    void traversal(vector<int>& nums, int startIndex) {
        result.push_back(vec);
        if(startIndex >= nums.size()) {
            return;
        }
        for(int i = startIndex; i < nums.size(); i++) {
            if(i > startIndex && nums[i] == nums[i - 1])
            {
                continue;
            }
            vec.push_back(nums[i]);
            traversal(nums, i + 1);
            vec.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        traversal(nums, 0);
        return result;
    }
};
// @lc code=end

