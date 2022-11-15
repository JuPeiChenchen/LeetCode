/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] > b[1];
        });
        int res = 0;
        for (auto &boxType : boxTypes) {
            int numberOfBoxes = boxType[0];
            int numberOfUnitsPerBox = boxType[1];
            if (numberOfBoxes < truckSize) {
                res += numberOfBoxes * numberOfUnitsPerBox;
                truckSize -= numberOfBoxes;
            } else {
                res += truckSize * numberOfUnitsPerBox;
                break;
            }
        }
        return res;
    }
};

// @lc code=end

