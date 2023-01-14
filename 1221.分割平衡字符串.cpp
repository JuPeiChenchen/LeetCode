/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
/*class Solution {
public:
    int balancedStringSplit(string s) {
        int result = 0;
        int slow = 0;
        int fast = 1;
        int left = 0;
        int right = 0;
        if(s[0] == 'L') {
            left++;
        }
        else {
            right++;
        }
        for(int i = 1; i < s.size(); i++) {
            if(left > 0 && left == right) {
                result++;
                cout<<left<<"   "<<i<<endl;
                left = 0;
                right = 0;
                
            }
            if(s[i] == 'L') {
                left++;
            }
            else {
                right++;
            }
        }
        if(left > 0 && left == right) {
            result++;
        }
        return result;
    }
};*/
class Solution {
public:
    int balancedStringSplit(string s) {
        int result = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') count++;
            else count--;
            if (count == 0) result++;
        }
        return result;
    }
};
// @lc code=end

