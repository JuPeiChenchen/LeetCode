/*
 * @lc app=leetcode.cn id=1781 lang=cpp
 *
 * [1781] 所有子字符串美丽值之和
 */

// @lc code=start
/*class Solution {
public:
    void traversal(string s, int startIndex) {

        for(int i = startIndex; i < s.size(); i++) {
            string a = 
        }
    }
    int beautySum(string s) {
        unordered_map<char, int> mp;
        int fastIndex = 1;
        int lowIndex = 0;
        mp[s[0]]++;
        mp[s[1]]++;
        int result = 0;
        while(fastIndex < s.size() && lowIndex < fastIndex) {
            if(mp.size() < 2) {
                fastIndex++;
                mps[s[fastIndex]]++;
            }
            if(mp.size() >= 2) {

            }
        }
        vector<int> b(26, 0);
        for(int i = 0; i < s.size() - 1; i++) {
            for(int j = i + 1; j < s.size(); j++) {
                //string a = str(s.begin() + i, s.begin() + j);
                int max  =0;
                int min = 500;
                
                for(int k = i; k <= j; k++) {
                    b[s[k] - 'a']++;
                    if(b[s[k] - 'a'] > max) max = b[s[k] - 'a'];
                    
                }
                for(int k = 0; k < 26; k++) {
                    if(b[k] < min && b[k] > 0) min = b[k]; 
                }
                
                result += (max - min);
            }
        }
        return result;
    }
};*/
class Solution {
public:
    int beautySum(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> cnt(26);
            int maxFreq = 0;
            for (int j = i; j < s.size(); j++) {
                cnt[s[j] - 'a']++;
                maxFreq = max(maxFreq, cnt[s[j] - 'a']); 
                int minFreq = s.size();
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] > 0) {
                        minFreq = min(minFreq, cnt[k]);
                    }
                }
                res += maxFreq - minFreq;
            }
        }
        return res;
    }
};

// @lc code=end

