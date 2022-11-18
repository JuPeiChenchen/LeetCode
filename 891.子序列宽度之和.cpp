/*
 * @lc app=leetcode.cn id=891 lang=cpp
 *
 * [891] 子序列宽度之和
 */

// @lc code=start
/*class Solution {
public:
    int result = 0;
    vector<int> path;
    void traversal(vector<int>& nums, int startIndex) {
        //cout<<path.size()<<endl;
        if(path.size() >= 2) {
        result += (*max_element(path.begin(),path.end())-*min_element(path.begin(),path.end())) % (1000000000 + 7);
        }
        
        for(int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            traversal(nums, i + 1);
            path.pop_back();
        }
    }
    int sumSubseqWidths(vector<int>& nums) {
        traversal(nums, 0);
        return result;
    }
};*/
class Solution {
    const int MOD = 1e9 + 7;
public:
    int sumSubseqWidths(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), pow2[n];
        pow2[0] = 1;
        for (int i = 1; i < n; ++i)
            pow2[i] = pow2[i - 1] * 2 % MOD; // 预处理 2 的幂次
        long ans = 0L;
        for (int i = 0; i < n; ++i)
            ans += long(pow2[i] - pow2[n - 1 - i]) * nums[i]; // 在题目的数据范围下，这不会溢出
        return (ans % MOD + MOD) % MOD; // 注意上面有减法，ans 可能为负数
    }
};

// @lc code=end

