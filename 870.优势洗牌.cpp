/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx1(n), idx2(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        sort(idx1.begin(), idx1.end(), [&](int i, int j) { return nums1[i] < nums1[j]; });
        sort(idx2.begin(), idx2.end(), [&](int i, int j) { return nums2[i] < nums2[j]; });
        
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (nums1[idx1[i]] > nums2[idx2[left]]) {
                ans[idx2[left]] = nums1[idx1[i]];
                ++left;
            }
            else {
                ans[idx2[right]] = nums1[idx1[i]];
                --right;
            }
        }
        return ans;
    }
};
/*class Solution {
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), ids[n];
        vector<int> ans(n);
        sort(nums1.begin(), nums1.end());
        iota(ids, ids + n, 0);
        sort(ids, ids + n, [&](int i, int j) { return nums2[i] < nums2[j]; });
        int left = 0, right = n - 1;
        for (int x : nums1)
            ans[x > nums2[ids[left]] ? ids[left++] : ids[right--]] = x;
        return ans;
    }
};

*/

// @lc code=end

