/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
/*class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char s : S) {
            if (st.empty() || s != st.top()) {
                st.push(s);
            } else {
                st.pop(); // s 与 st.top()相等的情况
            }
        }
        string result = "";
        while (!st.empty()) { // 将栈中元素放到result字符串汇总
            result += st.top();
            st.pop();
        }
        reverse (result.begin(), result.end()); // 此时字符串需要反转一下
        return result;

    }
};*/
class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for (char S : s)
        {
            if (result.empty() || result.back() != S)
            {
                result.push_back(S);
            }
            else
            {
                result.pop_back();
            }
        }
        return result;
    }
};
// @lc code=end

