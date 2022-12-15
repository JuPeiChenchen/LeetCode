/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= right && intervals[i][1] > right) {
                right = intervals[i][1];
            }
            else if(intervals[i][0] <= right && intervals[i][1] <= right) {
                continue;
            }
            else {
                result.push_back(vector<int>{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        result.push_back(vector<int>{left, right});
        return result;
    }
};
// @lc code=end

