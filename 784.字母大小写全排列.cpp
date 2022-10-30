/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> result;
    void traversal(string s, int startIndex, int flag) {
        if(flag == 1 && find(result.begin(), result.end(), s) == result.end()) {
            result.push_back(s);
        }
        for(int i = startIndex; i < s.size(); i++) {
            if((s[i] >= 'a' && s[i] <= 'z')) {
                s[i] = s[i] - 32;
                traversal(s, i + 1, 1);
                s[i] = s[i] + 32; 
            }
            else if((s[i] >= 'A' && s[i] <= 'Z')) {
                s[i] = s[i] + 32;
                traversal(s, i + 1, 1);
                s[i] = s[i] - 32;
            }
            else {
                traversal(s, i + 1, 0);
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        traversal(s, 0, 1);
        return result;
    }
};
/*class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        int m = 0;
        for (auto c : s) {
            if (isalpha(c)) {
                m++;
            }
        }
        vector<string> ans;
        for (int mask = 0; mask < (1 << m); mask++) {
            string str;
            for (int j = 0, k = 0; j < n; j++) {
                if (isalpha(s[j]) && (mask & (1 << k++))) {
                    str.push_back(toupper(s[j]));//小写转大写
                } else {
                    str.push_back(tolower(s[j]));
                }
            }
            ans.emplace_back(str);
        }
        return ans;
    }
};
*/
// @lc code=end

