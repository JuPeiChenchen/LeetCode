/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
/*class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int a = 0, b = 1;
        for (int i = 1; i < n; i++) {
            int at = a, bt = b;
            a = b = n;
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])  {
                a = min(a, at);
                b = min(b, bt + 1);
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                a = min(a, bt);
                b = min(b, at + 1);
            }
        }
        return min(a, b);
    }
};*/
int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[0][1]=1;
        for(int i=1;i<n;i++){
            if(nums1[i]>nums1[i-1]&&nums2[i]>nums2[i-1]&&nums2[i]>nums1[i-1]&&nums1[i]>nums2[i-1]){
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=min(dp[i-1][1],dp[i-1][0])+1;
            }
            else if(nums1[i]>nums1[i-1]&&nums2[i]>nums2[i-1]){
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1]+1;
            }
            else if(nums2[i]>nums1[i-1]&&nums1[i]>nums2[i-1]){
                dp[i][0]=dp[i-1][1];
                dp[i][1]=dp[i-1][0]+1;
            }         
        }
        return min(dp[n-1][0],dp[n-1][1]);
    }

// @lc code=end

