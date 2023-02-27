/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
class Solution {
private:
    static int bitCount(int n) { // 计算n的二进制中1的数量
        int count = 0;
        while(n) {
            n &= (n -1); // 清除最低位的1
            count++;
        }
        return count;
    }
    static bool cmp(int a, int b) {
        int bitA = bitCount(a);
        int bitB = bitCount(b);
        if (bitA == bitB) return a < b; // 如果bit中1数量相同，比较数值大小
        return bitA < bitB; // 否则比较bit中1数量大小
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
// @lc code=end

