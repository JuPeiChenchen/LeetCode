/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] 自定义字符串排序
 */

// @lc code=start
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26);
        for (char ch: s) {
            ++freq[ch - 'a'];
        }
        string ans;
        for (char ch: order) {
            if (freq[ch - 'a'] > 0) {
                ans += string(freq[ch - 'a'], ch);
                freq[ch - 'a'] = 0;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                ans += string(freq[i], i + 'a');
            }
        }
        return ans;
    }
};
/*class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> val(26);
        for (int i = 0; i < order.size(); ++i) {
            val[order[i] - 'a'] = i + 1;
        }
        sort(s.begin(), s.end(), [&](char c0, char c1) {
            return val[c0 - 'a'] < val[c1 - 'a'];
        });
        return s;
    }
};
*/
// @lc code=end

