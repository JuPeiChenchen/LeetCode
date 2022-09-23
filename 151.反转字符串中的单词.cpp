/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    void reverse(string& s, int start, int end) {
        int i = start;
        int j = end;
        for(; i <= (end + start) / 2; i++) {
            swap(s[i], s[j]);
            j--;
        }
    }
    void removespace(string& s) {
        int slow = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                if(slow != 0) {
                    s[slow++] = ' ';
                }
                    while(s[i] != ' ' && i < s.length()) {
                        s[slow++] = s[i++];
                    }
            }
            
        }
        s.resize(slow);
    }
    string reverseWords(string s) {
        /*int slow = 0;
        int fast = 0;
        while(s.length() > 0 && fast < s.length() && s[fast] == ' ') {
            fast++;
        }
        while(fast < s.length()) {
            if(fast - 1 > 0 && s[fast] == ' ' && s[fast] == s[fast - 1]) {
                fast++;
            }
            else {
                s[slow++] = s[fast];
                fast++;
            }
        }
        if(slow - 1 > 0 && s[slow - 1] == ' ') {
            s.resize(slow - 1);
        }
        else {
            s.resize(slow);
        }*/
        removespace(s);
        reverse(s, 0, s.length() - 1);
        int start = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                reverse(s , start, i - 1);
                start = i + 1;
            }
        }
        reverse(s, start, s.length() - 1);
        return s;
    }
};
// @lc code=end

