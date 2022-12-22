/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            int a = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(nums[i] > nums[j]) {
                    a++;
                }
            }
            result[i] = a;
        }
        /*for(int i = 1; i < nums.size(); i++) {
            if(nums[0] > nums[i]) {
                result[0]++;
            }
        }*/
        return result;
    }
};
/*class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end()); // 从小到大排序之后，元素下标就是小于当前数字的数字
        int hash[101];
        for (int i = vec.size() - 1; i >= 0; i--) { // 从后向前，记录 vec[i] 对应的下标
            hash[vec[i]] = i;
        }
        // 此时hash里保存的每一个元素数值 对应的 小于这个数值的个数
        for (int i = 0; i < nums.size(); i++) {
            vec[i] = hash[nums[i]];
        }
        return vec;
    }
};*/
// @lc code=end

