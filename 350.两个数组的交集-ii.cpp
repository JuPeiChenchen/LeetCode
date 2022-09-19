/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
/*class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> map;
        vector<int> result;
        for(int num : nums1) {
            map[num]++;
        }
        for(int num : nums2) {
            if(map.find(num) != map.end() && map[num] > 0) {
                result.push_back(num);
                map[num]--;
            }
        }
        return result;
    }
};*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> map;
        vector<int> result;
        for(int num : nums1) {
            map[num]++;
        }
        for(int num : nums2) {
            if(map.find(num) != map.end() && map[num] > 0) {
                result.push_back(num);
                map[num]--;
            }
        }
        return result;
    }
};
// @lc code=end

