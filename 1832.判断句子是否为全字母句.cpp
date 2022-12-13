/*
 * @lc app=leetcode.cn id=1832 lang=cpp
 *
 * [1832] 判断句子是否为全字母句
 */

// @lc code=start
class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size() < 26) {return false;}
        vector<int> result(26, 0);
        for(int i = 0; i < sentence.size(); i++) {
            result[sentence[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(result[i] == 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

