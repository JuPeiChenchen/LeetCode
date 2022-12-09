/*
 * @lc app=leetcode.cn id=1780 lang=cpp
 *
 * [1780] 判断一个数字是否可以表示成三的幂的和
 */

// @lc code=start
/*class Solution {
public:
    bool traversal(int n, int startIndex, int b, int sum) {
        if(sum == n) {
            return true;
        }
        if(sum > n) {
            return false;
        }
        for(int i = startIndex; i <= b; i++) {
            if(traversal(n, i + 1, b, sum + pow(3, i))) return true;
        }
        return false;
    }
    bool checkPowersOfThree(int n) {
        int i = 0;
        for(; i < n; i++) {
            if(pow(3, i) == n) {
                return true;
            }
            else if(pow(3, i) > n) {
                break;
            }
        }
        int sum =0;
        return traversal(n, 0, i, sum);
    }
};*/
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};

// @lc code=end

