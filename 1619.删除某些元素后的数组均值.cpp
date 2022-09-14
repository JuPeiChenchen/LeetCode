/*
 * @lc app=leetcode.cn id=1619 lang=cpp
 *
 * [1619] 删除某些元素后的数组均值
 */

// @lc code=start
class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int a = int(arr.size() * 0.05);
        double result = 0;
        for (int i = a; i < arr.size() - a; i++)
        {
            result += double(arr[i]) / double(arr.size() - 2 * a);
        }
        return result;
    }
};
// @lc code=end

