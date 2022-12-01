/*
 * @lc app=leetcode.cn id=1779 lang=cpp
 *
 * [1779] 找到最近的有相同 X 或 Y 坐标的点
 */

// @lc code=start
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int result = INT_MAX;
        int p = -1;
        for(int i = 0; i < points.size(); i++) {
            if(x == points[i][0] || y == points[i][1]) {
                int d = abs(x - points[i][0]) + abs(y - points[i][1]);
                if(d < result) {
                    result = d;
                    p = i;
                }
            }
        }
        return p;
    }
};
// @lc code=end

