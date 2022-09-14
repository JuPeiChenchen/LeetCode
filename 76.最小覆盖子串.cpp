/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    bool boolString(int a[], int b[]) {
        for(int i = 0; i < 60; i++) {
                if(a[i] < b[i]) {
                    return false;
                }
            }
            return true;
    }
    string minWindow(string s, string t) {
        if(s.length() < t.length()) {
            return "";
        }
        int slowindex = 0;
        int fastindex = 0;
        string result = "";
        int b[60] = {0};
        int a[60] = {0};
        for(int i = 0; i < t.length(); i++) {
                b[t[i] - 'A'] += 1;
            }
        for(; fastindex < s.length(); fastindex++) {
            string str = s.substr(slowindex, fastindex - slowindex + 1);
            a[s[fastindex] - 'A']++;
            while(boolString(a,b)) {
                if (result == "") {
                    result = str;
                }
                else {
                    if (result.length() > str.length()) {
                        result = str;
                    }
                }
                a[s[slowindex] - 'A']--;
                slowindex++;
                str = s.substr(slowindex, fastindex - slowindex + 1);
            }
        }
        return result;
    }
};
// @lc code=end

