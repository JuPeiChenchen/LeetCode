/*
 * @lc app=leetcode.cn id=1945 lang=cpp
 *
 * [1945] 字符串转化后的各位数字之和
 */

// @lc code=start
class Solution {
public:
    int getLucky(string s, int k) {
        int result = 0;
        for(int i = 0; i < s.size(); i++) {
            int a = s[i] - 'a' + 1;
            while(a > 0) {
                result += a % 10;
                a /= 10;
            }
        }
        cout<<result<<endl;
        for(int i = 1; i < k; i++) {
            int b = 0;
            while(result > 0) {
                b += result % 10;
                result /= 10;
            }
            result = b;
        }
        return result;
    }
};
// @lc code=end

