/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> b) {
            return a[0] < b[0];
        });
        int result = 0;
        int mi = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < mi && intervals[i][1] <= mi) {
                result++;
                mi = intervals[i][1];
            }
            else if(intervals[i][0] < mi) {
                result++;
            }
            else {
                mi = intervals[i][1];
            }
        }
        return result;
    }
};
// @lc code=end

