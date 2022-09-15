/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int startx = 0;
        int starty = 0;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
        int x = 1;
        while(loop-- != 0) {
            int i = 0;
            int j = 0;
            for(i = starty; i < n - x; i++) {
                result[startx][i] = count++;
            }
            for(j = startx; j < n - x; j++) {
                result[j][i] = count++;
            }
            for(; i > startx; i--) {
                result[j][i] = count++;
            }
            for(; j > starty; j--) {
                result[j][i] = count++;
            }
            startx++;
            starty++;
            x++;
        }
        if(n % 2 != 0) {
            result[mid][mid] = count;
        }
        return result;
    }
};
// @lc code=end

