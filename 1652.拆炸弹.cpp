/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(); //获取数组元素个数
        vector<int> ans(n);  //创建新数组，大小同code
        if (k == 0) return ans; //特判
        code.resize(n * 2); //修改数组大小
        copy(code.begin(), code.begin() + n, code.begin() + n);
        int l = k > 0 ? 1 : n + k; //左指针
        int r = k > 0 ? k : n - 1; //右指针
        int w = 0;//滑动窗口的值
        for (int i = l; i <= r; i++) {
            w += code[i];//求和
        }
        for (int i = 0; i < n; i++) {
            ans[i] = w;//答案数组的当前值就是为滑动窗口的值
            w -= code[l];//右移去掉left值
            l++;//左指针+1
            r++;//右指针+1
            w += code[r];//右移加上right值
        }
        return ans;
    }
};
// @lc code=end

