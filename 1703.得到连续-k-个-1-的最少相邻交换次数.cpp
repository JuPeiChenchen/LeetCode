/*
 * @lc app=leetcode.cn id=1703 lang=cpp
 *
 * [1703] 得到连续 K 个 1 的最少相邻交换次数
 */

// @lc code=start
class Solution {
private:
    vector<int> zeros;
    vector<int> pre {0};
    
    void GenerateZeros(const vector<int> &nums) {
        int n = nums.size(), i = 0;
        while (i < n && nums[i] == 0) i++;
        while (i < n) {
            int j = i+1;
            while (j < n && nums[j] == 0) j++;
            if (j < n) zeros.push_back(j-i-1);
            i = j;
        }
    }
    
    void GeneratePresum(vector<int>& zeros) {
        for (int i = 0; i < zeros.size(); i++) {
            pre.push_back(pre.back() + zeros[i]);
        }
    }
    
    int GetRangeSum(int left, int right) {
        return pre[right+1] - pre[left];
    }
    
public:
    int minMoves(vector<int>& nums, int k) {
        GenerateZeros(nums);                        //第一步：生成zeros
        
        int cost = 0;                               //第二步：计算第一个窗口的解
        int left = 0, right = k-2;
        for (int i = left; i <= right; i++) {
            cost += zeros[i] * (min(i+1, right-i+1));
        }
        
        int minCost = cost;
        
        GeneratePresum(zeros);                      //第三步：开始滑动窗口
        int i = 1, j = i + k - 2;
        for (; j < zeros.size(); i++, j++) {
            int mid = (i + j) / 2;
            cost -= GetRangeSum(i-1, mid-1);
            cost += GetRangeSum(mid+k%2, j);
            minCost = min(minCost, cost);
        }
        
        return minCost;
    }
};

// @lc code=end

