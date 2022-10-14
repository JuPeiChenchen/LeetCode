/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> last(26, -1);
        
        int n = s.size();
        vector<int> f(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (last[j] != -1) {
                    f[i] = (f[i] + f[last[j]]) % mod;
                }
            }
            last[s[i] - 'a'] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (last[i] != -1) {
                ans = (ans + f[last[i]]) % mod;
            }
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};
/*class Solution {
public:
    int distinctSubseqII(string S) {
        vector<long int> line(26);
        int size=S.size();
        for(int i=0;i<size;i++){
            long int sum=0;
            for(int j=0;j<26;j++){
                sum=(sum+line[j])%1000000007;
            }
            line[S[i]-'a']=sum+1;
        }
        long int result=0;
        for(int i=0;i<26;i++){
            result=(result+line[i])%1000000007;
        }
        return result;
    }
};*/
// @lc code=end

