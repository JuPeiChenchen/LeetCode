/*
 * @lc app=leetcode.cn id=1684 lang=cpp
 *
 * [1684] 统计一致字符串的数目
 */

// @lc code=start
class Solution {
public:
    bool aa(vector<int> a, string s) {
        for(int i = 0; i < s.size(); i++) {
            if(a[s[i] - 'a'] == 0) {
                return false;
            }
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        int result = 0;
        vector<int> a(26,0);
        for(int i = 0; i < allowed.size(); i++) {
            a[allowed[i] - 'a'] = 1;
            //cout<<allowed[i]<<endl;
        }
        for(int i = 0; i < words.size(); i++) {
            if(aa(a, words[i])) {
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

