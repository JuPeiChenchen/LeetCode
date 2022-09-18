/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
/*class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result ;
        map<string, vector<string>> a;
        if(strs.size() == 0 || strs.size() == 1) {
            result.push_back(strs);
            return result;
        }
        for(int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            a[str].push_back(strs[i]);
        }
        for(auto it = a.begin(); it != a.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result ;
        map<vector<int>, vector<string>> a;
        if(strs.size() == 0 || strs.size() == 1) {
            result.push_back(strs);
            return result;
        }
        for(int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            vector<int> x(26);
            for(int j = 0; j < str.length(); j++) {
                x[str[j] - 'a']++;
            }
            a[x].push_back(strs[i]);
        }
        for(auto it = a.begin(); it != a.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};
// @lc code=end

