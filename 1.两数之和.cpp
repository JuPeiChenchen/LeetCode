/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        multiset<int> a;
        for(int num : nums) {
            a.insert(num);
        }
        int x = -1;
        for(auto it = a.begin(); it != a.end(); it++) {
            if(a.find(target - *it) != a.end()) {
                x = *it;
                break;
            }
        }
        int flag = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(flag == 2) {
                break;
            }
            if(nums[i] == x || nums[i] == target - x) {
                result.push_back(i);
                flag++;
            }
        }
        return result;
    }
};
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> a;
        for(int i = 0; i < nums.size(); i++)
        {
            auto iter = a.find(target - nums[i]);
            if(iter != a.end())
            {
                return {iter ->second, i};
            }
            a.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};*/
// @lc code=end

