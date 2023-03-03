/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 *
 * [1487] 保证文件名唯一
 */

// @lc code=start
/*class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> result;
        for(int i = 0; i < names.size(); i++) {
            if(find(result.begin(), result.end(), names[i]) == result.end()) {
                result.push_back(names[i]);
            }
            else {
                for(int j = 1; ; j++) {
                    if(find(result.begin(), result.end(), names[i] + "(" + to_string(j) + ")") == result.end()) {
                        result.push_back(names[i] + "(" + to_string(j) + ")");
                        break;
                    }
                }
            }
        }
        return result;
    }
};*/
class Solution {
public:
    string addSuffix(string name, int k) {
        return name + "(" + to_string(k) + ")";
    }

    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> index;
        vector<string> res;
        for (const auto &name : names) {
            if (!index.count(name)) {
                res.push_back(name);
                index[name] = 1;
            } else {
                int k = index[name];
                while (index.count(addSuffix(name, k))) {
                    k++;
                }
                res.push_back(addSuffix(name, k));
                index[name] = k + 1;
                index[addSuffix(name, k)] = 1;
            }
        }
        return res;
    }
};

// @lc code=end

