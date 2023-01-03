/*
 * @lc app=leetcode.cn id=2042 lang=cpp
 *
 * [2042] 检查句子中的数字是否递增
 */

// @lc code=start
class Solution {
public:
    bool areNumbersAscending(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); ) {
            if(s[i] >= '0' && s[i] <= '9') {
            int j = i;
            while(s[j] >= '0' && s[j] <= '9') {
                j++;
            }
            string p = s.substr(i, j - i);
            if(!st.empty() && st.top() >= stoi(p)) {
                return false;
            }
            st.push(stoi(p));
            i = j;
        }
        i++;
        }
        return true;
    }
};
/*class Solution {
public:
    bool areNumbersAscending(string s) {
        int pre = 0, pos = 0;
        while (pos < s.size()) {
            if (isdigit(s[pos])) {
                int cur = 0;
                while (pos < s.size() && isdigit(s[pos])) {
                    cur = cur * 10 + s[pos] - '0';
                    pos++;
                }
                if (cur <= pre) {
                    return false;
                }
                pre = cur;
            } else {
                pos++;
            }
        }
        return true;
    }
};
*/
// @lc code=end

