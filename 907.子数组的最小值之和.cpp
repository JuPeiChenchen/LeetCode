/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution {
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        // 左边界 left[i] 为左侧严格小于 arr[i] 的最近元素位置（不存在时为 -1）
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop(); // 移除无用数据
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }

        // 右边界 right[i] 为右侧小于等于 arr[i] 的最近元素位置（不存在时为 n）
        vector<int> right(n, n);
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop(); // 移除无用数据
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }

        long ans = 0L;
        for (int i = 0; i < n; ++i)
            ans += (long) arr[i] * (i - left[i]) * (right[i] - i); // 累加贡献
        return ans % MOD;
    }
};
/*class Solution {
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                right[st.top()] = i; // i 恰好是栈顶的右边界
                st.pop();
            }
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }

        long ans = 0L;
        for (int i = 0; i < n; ++i)
            ans += (long) arr[i] * (i - left[i]) * (right[i] - i); // 累加贡献
        return ans % MOD;
    }
};
*/
/*class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        long long mod = 1e9 + 7;
        stack<int> monoStack;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            while (!monoStack.empty() && arr[monoStack.top()] > arr[i]) {
                monoStack.pop();
            }
            int k = monoStack.empty() ? (i + 1) : (i - monoStack.top());
            dp[i] = k * arr[i] + (monoStack.empty() ? 0 : dp[i - k]);
            ans = (ans + dp[i]) % mod;
            monoStack.emplace(i);
        }
        return ans;
    }
};
*/
// @lc code=end

