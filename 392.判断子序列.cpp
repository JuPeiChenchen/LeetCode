/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i, j;
        for(i = 0, j = 0; i < s.size(), j < t.size();) {
            if(s[i] == t[j]) {
                cout<<s[i]<<t[j]<<endl;
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        cout<<i;
        if(i < s.size()) {
            return false;
        }
        return true;
    }
};
/*class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1];
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
};*/
// @lc code=end

