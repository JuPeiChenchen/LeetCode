/*
 * @lc app=leetcode.cn id=1640 lang=cpp
 *
 * [1640] 能否连接形成数组
 */

// @lc code=start
/*class Solution {
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
        unordered_map<int, int> index;
        for (int i = 0; i < pieces.size(); i++) {
            index[pieces[i][0]] = i;
        }
        for (int i = 0; i < arr.size();) {
            auto it = index.find(arr[i]);
            if (it == index.end()) {
                return false;
            }
            for (int x : pieces[it->second]) {
                if (arr[i++] != x) {
                    return false;
                }
            }
        }
        return true;
    }
};*/
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int i = 0, j = 0, n = arr.size();
        for ( ;i < n; ) {
            bool find = false;
            for (auto p : pieces)
                if (p[0] == arr[i]) {
                    find = true;
                    j = 0;
                    while (j < p.size() && i < n && p[j] == arr[i]) {
                        i++;
                        j++;
                    }
                    if (j != p.size()) {
                        return false;
                    }
                    break;
                }
            if (!find)
                return false;
        }
        if (i != n)
            return false;
        return true;
    }
};

// @lc code=end

