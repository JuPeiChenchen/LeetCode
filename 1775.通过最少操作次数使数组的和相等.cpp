/*
 * @lc app=leetcode.cn id=1775 lang=cpp
 *
 * [1775] 通过最少操作次数使数组的和相等
 */

// @lc code=start
/*class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        int sum = 0;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < nums1.size(); i++) {
            sum += nums1[i];
            sum1 += nums1[i];
        }
        for(int i = 0; i < nums2.size(); i++) {
            sum += nums2[i];
            sum2 += nums2[i];
        }
        sum /= 2;
        int max1 = nums1.size() * 6;
        int max2 = nums2.size() * 6;
        if(nums1.size() > max2 || nums2.size() > max1) {
            return -1;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        if(sum1 > sum2) {
            if(sum1 - sum2 <= 6 - nums2[0] || sum1 - sum2 <= nums1[nums1.size() - 1] - 1) {
                return 1;
            }
        }
        if(sum1 < sum2) {
            if(sum2 - sum1 <= 6 - nums1[0] || sum2 - sum1 <= nums2[nums2.size() - 1] - 1) {
                return 1;
            }
        }
        if(sum2 > sum) {
            int i = nums2.size() - 1;
            while(sum2 > sum) {
                if(nums2[i] - 1 < sum2 - sum) {
                    sum2 -= (nums2[i] - 1);
                    result++;
                    i--;
                }
                else {
                    result++;
                    break;
                }
            }
        }
        else {
            int i = 0;
            while(sum2 < sum) {
                if(6 - nums2[i] < sum - sum2) {
                    sum2 += (6 - nums2[i]);
                    result++;
                    i++;
                }
                else {
                    result++;
                    break;
                }
            }
        }
        if(sum1> sum) {
            int i = nums1.size() - 1;
            while(sum1 > sum) {
                if(nums1[i] - 1 < sum1 - sum) {
                    sum1 -= (nums1[i] - 1);
                    result++;
                    i--;
                }
                else {
                    result++;
                    break;
                }
            }
        }
        else {
            int i = 0;
            while(sum1 < sum) {
                if(6 - nums1[i] < sum - sum1) {
                    sum1 += (6 - nums1[i]);
                    result++;
                    i++;
                }
                else {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};*/
class Solution {
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2) {
        if (6 * nums1.size() < nums2.size() || 6 * nums2.size() < nums1.size())
            return -1; // 优化
        int d = accumulate(nums2.begin(), nums2.end(), 0) - accumulate(nums1.begin(), nums1.end(), 0);
        if (d < 0) {
            d = -d;
            swap(nums1, nums2); // 统一让 nums1 的数变大，nums2 的数变小
        }
        int cnt[6]{}; // 统计每个数的最大变化量
        for (int x: nums1) ++cnt[6 - x]; // nums1 的变成 6
        for (int x: nums2) ++cnt[x - 1]; // nums2 的变成 1
        for (int i = 5, ans = 0;; --i) { // 从大到小枚举最大变化量 5 4 3 2 1
            if (i * cnt[i] >= d) // 可以让 d 变为 0
                return ans + (d + i - 1) / i;
            ans += cnt[i]; // 需要所有最大变化量为 i 的数
            d -= i * cnt[i];
        }
    }
};

// @lc code=end

