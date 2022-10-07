/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> result;
    string st;
    vector<int> path;
    void traversal(string s, int startIndex) {
        if(path.size() == 4 && startIndex == s.size()) {
            string a;
            for(int i = 0; i < 3; i++) {
                string p = to_string(path[i]);
                a += p;
                a += ".";
            }
            a += to_string(path[3]);
            result.push_back(a);
            return;
        }
        for(int i = startIndex; i < s.size(); i++) {
            string ss = s.substr(startIndex, i - startIndex + 1);
            if(manzu(s, startIndex, i)) {
                int a = stoi(ss);
                path.push_back(a);
            }
            else {
                continue;
            }
            traversal(s, i + 1);
            path.pop_back();
            
        }
    }
    bool manzu(string s, int start, int end) {
        if(end - start + 1 > 4) {
            return false;
        }
        string ss = s.substr(start, end - start + 1);
        int a = stoi(ss);
        if(s[start] != '0' && a <= 255) {
            return true;
        }
        else if(s[start] == '0' && end - start + 1 == 1){
            return true;
        }
        return false;
    }
    vector<string> restoreIpAddresses(string s) {
        traversal(s, 0);
        return result;
    }
};



// @lc code=end

