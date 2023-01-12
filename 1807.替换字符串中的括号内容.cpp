/*
 * @lc app=leetcode.cn id=1807 lang=cpp
 *
 * [1807] 替换字符串中的括号内容
 */

// @lc code=start
/*class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        for(int i = 0; i < s.size(); i++) {
            int left;
            if(s[i] == '(') {
                left = i;
            }
            else if(s[i] == ')') {
                string str = s.substr(left + 1, i - left - 1);
                //cout<<str<<endl;
                int flag = 0;
                for(int j = 0; j < knowledge.size(); j++) {
                    if(str == knowledge[j][0]) {
                        flag = 1;
                        s.replace(left, i - left + 1, knowledge[j][1]);
                        break;
                    }
                }
                if(flag == 0) {
                    s.replace(left, i - left + 1, "?");
                }
                cout<<s<<endl;
                i = 0;
            }
        }
        return s;
    }
};*/
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (auto &kd : knowledge) {
            dict[kd[0]] = kd[1];
        }
        bool addKey = false;
        string key, res;
        for (char c : s) {
            if (c == '(') {
                addKey = true;
            } else if (c == ')') {
                if (dict.count(key) > 0) {
                    res += dict[key];
                } else {
                    res.push_back('?');
                }
                addKey = false;
                key.clear();
            } else {
                if (addKey) {
                    key.push_back(c);
                } else {
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};

// @lc code=end

