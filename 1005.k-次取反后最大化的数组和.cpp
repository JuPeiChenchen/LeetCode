/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
/*class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size();) {
            if(k > 0 && nums[i] < 0) {
                nums[i] = -1 * nums[i];
                i++;
                k--;
            }
            else if(k > 0 && nums[i] == 0) {
                break;
            }
            else if(k > 0) {
                if(abs(nums[i]) < abs(nums[i - 1])) {
                    while(k > 0) {
                        nums[i] *= -1;
                    }
                }
                    else {
                        while(k > 0) {
                            nums[i - 1] *= -1;
                        }
                    }
                break;
        }
    }
    for(int i = 0; i < nums.size(); i++) {
        result += nums[i];
    }
    return result;
    }
};*/
class Solution {
static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);       // 第一步
        for (int i = 0; i < A.size(); i++) { // 第二步
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        if (K % 2 == 1) A[A.size() - 1] *= -1; // 第三步
        int result = 0;
        for (int a : A) result += a;        // 第四步
        return result;
    }
};
// @lc code=end

