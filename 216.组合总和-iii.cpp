/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> vec;
    //int count;
    void traversal(int k, int n, int start, int count) {
        //cout<<count<<endl;
        if(vec.size() == k ) {
            if(count == n) result.push_back(vec);
            return;
        }
        for(int i = start; i <= 9; i++) {
            count += i;
            vec.push_back(i);
            
            traversal(k, n, i + 1, count);
            count -= i;
            vec.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //count = 0;
        traversal(k, n, 1, 0);
        return result;
    }
};
/*class Solution {
private:
    vector<vector<int>> result; // 存放结果集
    vector<int> path; // 符合条件的结果
    void backtracking(int targetSum, int k, int sum, int startIndex) {
        if (sum > targetSum) { // 剪枝操作
            return; // 如果path.size() == k 但sum != targetSum 直接返回
        }
        if (path.size() == k) {
            if (sum == targetSum) result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) { // 剪枝
            sum += i; // 处理
            path.push_back(i); // 处理
            backtracking(targetSum, k, sum, i + 1); // 注意i+1调整startIndex
            sum -= i; // 回溯
            path.pop_back(); // 回溯
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear(); // 可以不加
        path.clear();   // 可以不加
        backtracking(n, k, 0, 1);
        return result;
    }
};*/
// @lc code=end

