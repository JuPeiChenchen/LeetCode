/*
 * @lc app=leetcode.cn id=1805 lang=cpp
 *
 * [1805] 字符串中不同整数的数目
 */

// @lc code=start
/*class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> result;
        string s = "";
        int flag = 0;
        for(int i = 0; i < word.size(); i++) {
            if(isalpha(word[i])) {
                if(s.size() > 0) {
                    cout<<s.size()<<endl;
                    while(s.size() >= 1 && s[0] == '0') {
                        s.erase(0, 1);
                    }
                    result.insert(s);
                    s = "";
                }
            }
            else {
                s += word[i];
            }
        }
        if(s.size() > 0) {
                    while(s[0] == '0') {
                        s.erase(s[0]);
                    }
                    result.insert(s);
                    s = "";
                }
        return result.size();
    }
};*/
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        int n = word.size(), p1 = 0, p2;
        while (true) {
            while (p1 < n && !isdigit(word[p1])) {
                p1++;
            }
            if (p1 == n) {
                break;
            }
            p2 = p1;
            while (p2 < n && isdigit(word[p2])) {
                p2++;
            }
            while (p2 - p1 > 1 && word[p1] == '0') { // 去除前导 0
                p1++;
            }
            s.insert(word.substr(p1, p2 - p1));
            p1 = p2;
        }
        return s.size();
    }
};

// @lc code=end

