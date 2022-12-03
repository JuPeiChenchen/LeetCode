/*
 * @lc app=leetcode.cn id=1796 lang=cpp
 *
 * [1796] 字符串中第二大的数字
 */

// @lc code=start
/*class Solution {
public:
    int secondHighest(string s) {
        int pre = -1;
        int result = -1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                
                if(s[i] - '0' > pre) {
                    pre = s[i] - '0';
                }
                else if(s[i] - '0' < pre && s[i] - '0' > result) {
                    result = s[i] - '0';
                }
            }
        }
        
        return result;
    }
};*/
class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (auto c : s) {
            if (isdigit(c)) {
                int num = c - '0';
                if (num > first) {
                    second = first;
                    first = num;
                } else if (num < first && num > second) {
                    second = num;
                }
            }
        }
        return second;
    }
};

// @lc code=end

