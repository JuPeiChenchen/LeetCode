/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string s, vector<string> &words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }
        int res = words.size();
        for (auto &w : words) {
            if (w.size() > s.size()) {
                --res;
                continue;
            }
            int p = -1;
            for (char c : w) {
                auto &ps = pos[c - 'a'];
                auto it = upper_bound(ps.begin(), ps.end(), p);
                if (it == ps.end()) {
                    --res;
                    break;
                }
                p = *it;
            }
        }
        return res;
    }
};
/*class Solution {
public:
    int numMatchingSubseq(string s, vector<string> &words) {
        vector<queue<pair<int, int>>> queues(26);
        for (int i = 0; i < words.size(); ++i) {
            queues[words[i][0] - 'a'].emplace(i, 0);
        }
        int res = 0;
        for (char c : s) {
            auto &q = queues[c - 'a'];
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                ++j;
                if (j == words[i].size()) {
                    ++res;
                } else {
                    queues[words[i][j] - 'a'].emplace(i, j);
                }
            }
        }
        return res;
    }
};
*/
// @lc code=end

