/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startx = 0;
        int starty = 0;
        int loop = min(matrix.size() / 2, matrix[0].size() / 2);
        vector<int> result(matrix.size() * matrix[0].size(), 0);
        int offset = 1;
        int x = 0;
        if (matrix.size() == 1 || matrix[0].size() == 1) {
            if(matrix.size() == matrix[0].size()) {
                int mid = matrix.size() / 2;
                result[x] = matrix[mid][mid];
            }
            else if(matrix.size() > matrix[0].size()) {
                int mid = matrix[0].size() / 2;
                for(int i = 0; i < matrix.size(); i++) {
                    result[x] = matrix[i][0];
                    x++;
                }
            }
            else {
                int mid = matrix.size() / 2;
                for(int i = 0; i < matrix[0].size(); i++) {
                    result[x] = matrix[0][i];
                    x++;
                }
            }
            return result;
        }
        while(loop--) {
            int i = startx;
            int j = starty;
            for(; j < matrix[0].size() - offset; j++) {
                result[x] = matrix[i][j];
                x++;
            }
            for(; i < matrix.size() - offset; i++) {
                result[x] = matrix[i][j];
                x++;
            }
            for(; j > starty; j--) {
                result[x] = matrix[i][j];
                x++;
            }
            for(; i > startx; i--) {
                result[x] = matrix[i][j];
                x++;
            }
            startx++;
            starty++;
            offset++;
        }
        if((matrix.size() % 2 != 0 || matrix[0].size() % 2 != 0) && (matrix.size() > 2 && matrix[0].size() > 2)) {
            if(matrix.size() == matrix[0].size()) {
                int mid = matrix.size() / 2;
                result[x] = matrix[mid][mid];
            }
            else if(matrix[0].size() % 2 != 0 && matrix.size() % 2 == 0) {
                int mid = matrix[0].size() / 2;
                for(int i = startx; i < matrix.size() - matrix[0].size() + startx + 1; i++) {
                    result[x] = matrix[i][mid];
                    x++;
                }
            }
            else if(matrix.size() % 2 != 0 && matrix[0].size() %2 == 0) {
                int mid = matrix.size() / 2;
                for(int i = starty; i < matrix[0].size() - matrix.size() + starty + 1; i++) {
                    result[x] = matrix[mid][i];
                    x++;
                }
            }
            else {
                if(matrix.size() > matrix[0].size()) {
                    int mid = matrix[0].size() / 2;
                    for(int i = startx; i < matrix.size() - matrix[0].size() + startx + 1; i++) {
                        result[x] = matrix[i][mid];
                        x++;
                    }
            }
                else {
                    int mid = matrix.size() / 2;
                    for(int i = starty; i < matrix[0].size() - matrix.size() + starty + 1; i++) {
                        result[x] = matrix[mid][i];
                        x++;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

