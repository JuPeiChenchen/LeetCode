// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if(nums[0] > 0 || nums[nums.size() - 1] < 0) {
            return result;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
            return result;
        }
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            vector<int> set;
            while (right > left) {
                if(nums[i] + nums[left] + nums[right] > 0) {right--; }
                else if(nums[i] + nums[left] + nums[right] < 0) {left++;}
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while(left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    right--;
                    left++;
                }
                
            }
        }
        return result;
    }
};
// @lc code=end

