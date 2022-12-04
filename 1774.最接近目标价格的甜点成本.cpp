/*
 * @lc app=leetcode.cn id=1774 lang=cpp
 *
 * [1774] 最接近目标价格的甜点成本
 */

// @lc code=start
/*class Solution {
public:
    int ans = 0x3f3f3f3f; 
    int closestCost(vector<int>& base, vector<int>& top, int target) {
        for (int x : base) dfs(0, x, target, top);
        return ans;
    }
    void dfs(int x, int sum , int target, vector<int>& top) { 
        int a = abs(target - sum), b = abs(target - ans);
        if (a < b) ans = sum;
        if (a == b && sum < ans) ans = sum; 
        if (sum > target) return;
        for (int i = x; i < top.size(); i++) {
            dfs(i + 1, sum + top[i], target, top);
            dfs(i + 1, sum + 2 * top[i], target, top);
        }
    } 
};*/
class Solution {
public:
    int closestCost(vector<int>& base, vector<int>& top, int V) {
        vector<bool> dp(V + 5);
        int ans = 0x3f3f3f3f;
        for (int x : base) { //判断只能选基料
            if (x > V) ans = min(ans, x);
            else dp[x] = true;
        }
        for (int x : top) {
            for (int i = 0; i < 2; i++) { //选2次
                for (int j = V; j >= 0; j--) { 
                    if (dp[j] && j + x > V) ans = min(ans, j + x); //计算大于的情况
                    if (j > x) dp[j] = dp[j] | dp[j - x];
                }
            }
        }
        //ans-V:目前获得与target的差距 
        for (int i = 0; i <= ans - V && i <= V; i++) if (dp[V - i]) return V - i;
        return ans;
    }
};



// @lc code=end

