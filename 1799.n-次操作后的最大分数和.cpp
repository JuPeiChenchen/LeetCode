/*
 * @lc app=leetcode.cn id=1799 lang=cpp
 *
 * [1799] N 次操作后的最大分数和
 */

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size();
        int g[m][m];
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                g[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int f[1 << m];
        memset(f, 0, sizeof f);
        for (int k = 0; k < 1 << m; ++k) {
            int cnt = __builtin_popcount(k);
            if (cnt % 2 == 0) {
                //cout<<k<<endl;
                for (int i = 0; i < m; ++i) {
                    if (k >> i & 1) {
                        for (int j = i + 1; j < m; ++j) {
                            if (k >> j & 1) {
                                f[k] = max(f[k], f[k ^ (1 << i) ^ (1 << j)] + cnt / 2 * g[i][j]);
                                //cout<<(1 << j)<<endl;
                            }
                        }
                    }
                }
            }
        }
        return f[(1 << m) - 1];
    }
};

// @lc code=end

