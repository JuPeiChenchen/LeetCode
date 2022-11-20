/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

// @lc code=start
/*class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int sum = 0;
        double result = 0;
        if(poured == 0) {
            return result;
        }
        for(int i = 0; i < query_row; i++) {
            sum += (i + 1);
        }
        cout<<sum<<endl;
        if(poured < sum) {
            return result;
        }
        int sum1 = 0;
        for(int i = 0; i <= query_row; i++) {
            sum1 += (i + 1);
        }
        if(poured >= sum1) {
            result = 1;
            return result;
        }
        if(query_glass == 0 || query_glass == query_row) {
            result = (poured - sum) / (query_row * 2.0);
        }
        else  {
            result = 2.0 * (poured - sum) / (query_row * 2.0);
        }
        return result;
    }
};*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row = {(double)poured};
        for (int i = 1; i <= query_row; i++) {
            vector<double> nextRow(i + 1, 0.0);
            for (int j = 0; j < row.size(); j++) {
                double volume = row[j];
                if (volume > 1) {
                    nextRow[j] += (volume - 1) / 2;
                    nextRow[j + 1] += (volume - 1) / 2;
                }
            }
            row = nextRow;
        }            
        return min(1.0, row[query_glass]);
    }
};


// @lc code=end

