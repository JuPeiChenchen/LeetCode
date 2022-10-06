/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> vec;
    void traversal(int n, int k, int start) {
        if(vec.size() == k) {
            result.push_back(vec);
            return;
        }
        for(int i = start; i <= n; i++) {
            vec.push_back(i);
            traversal(n, k, i + 1);
            vec.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        traversal(n, k, 1);
        return result;
    }
};
/*class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) { // 优化的地方
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1);
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};*/
// @lc code=end

