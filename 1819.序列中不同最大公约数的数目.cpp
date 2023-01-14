/*
 * @lc app=leetcode.cn id=1819 lang=cpp
 *
 * [1819] 序列中不同最大公约数的数目
 */

// @lc code=start
/*class Solution {
    unordered_set<int> result;
public:
    int g(vector<int>& path) {

    }
    void traversal(vector<int>& nums, int startIndex, vector<int>& path) {
        if(path.size() > 0) {
            result.insert(g(path));
        }
        for(int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            traversal(nums, i + 1; path);
            path.pop_back();
        }
    }
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        vector<int> path;
        traversal(nums, 0, path);
        return result.size();
    }
};*/
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> occured(maxVal + 1, false);
        for (int num : nums) {
            occured[num] = true;
        }
        int ans = 0;
        for (int i = 1; i <= maxVal; i++) {
            int subGcd = 0;
            for (int j = i; j <= maxVal; j += i) {
                if (occured[j]) {
                    if (subGcd == 0) {
                        subGcd = j;
                    } else {
                        subGcd = __gcd(subGcd, j);
                        
                    }
                    if (subGcd == i) {
                        cout<<subGcd<<endl;
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

// @lc code=end

