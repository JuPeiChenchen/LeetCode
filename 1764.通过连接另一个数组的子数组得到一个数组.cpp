/*
 * @lc app=leetcode.cn id=1764 lang=cpp
 *
 * [1764] 通过连接另一个数组的子数组得到一个数组
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int> &g, vector<int> &nums, int k) {
        if (k + g.size() > nums.size()) {
            return false;
        }
        for (int j = 0; j < g.size(); j++) {
            if (g[j] != nums[k + j]) {
                return false;
            }
        }
        return true;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0;
        for (int k = 0; k < nums.size() && i < groups.size();) {
            if (check(groups[i], nums, k)) {
                k += groups[i].size();
                i++;
            } else {
                k++;
            }
        }
        return i == groups.size();
    }
};
/*class Solution {
public:
    int find(vector<int> &nums, int k, vector<int> &g) {
        int m = g.size(), n = nums.size();
        if (k + g.size() > nums.size()) {
            return -1;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && g[i] != g[j]) {
                j = pi[j - 1];
            }
            if (g[i] == g[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = k, j = 0; i < n; i++) {
            while (j > 0 && nums[i] != g[j]) {
                j = pi[j - 1];
            }
            if (nums[i] == g[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < groups.size(); i++) {
            k = find(nums, k, groups[i]);
            if (k == -1) {
                return false;
            }
            k += groups[i].size();
        }
        return true;
    }
};
*/
// @lc code=end

