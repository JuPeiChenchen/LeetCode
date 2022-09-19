/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> a(nums1.begin(),nums1.end());
        for(int num : nums2) {
            if(a.find(num) != a.end()) {
                result.insert(num);
            }
        }
        return vector<int> (result.begin(), result.end());
    }
};
// @lc code=end

