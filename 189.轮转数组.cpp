/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
/*class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k = k % nums.size();
        int n = nums.size() - k;
        vector<int> a = nums;
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = a[(i + n) % nums.size()];
        }
    }
};*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

    }
};
// @lc code=end

